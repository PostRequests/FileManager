#include "Display.h"
Display& Display::DrawPath() {
	cBack.reset();
	int needSize = box.width() - 1; //������ ������ ������������� � ����
	Position pos(box.getCurPoint()); //������������� ����� �� ������� �������
	pos.prevLine();
	std::string path = dir.getPath(); //������� ����
	path.resize(needSize); //�������� ������ ������, ���� �� ������� �� ������� ������
	system("chcp 866>nul");
	pos.go();
	std::cout << std::string(needSize, Board_H2);
	system("chcp 1251>nul");
	pos.printLn(path); //������� ����� �������� ����
	return *this;
}
void Display::reset() {
	cur = 0;
	pi = 0;
	pa = papa;
	dir.fill();
	Draw();
}
void Display::pires() {
	cur = 0;
	pi = 0;
	pa = papa;
	dir.fill();
}
void Display::resizeList(std::vector<std::string>& list) {
	std::vector<std::string> buf = dir.buffer.getFileNames();
	std::vector<int> alloc;
	//������������ ��������� ��� �������������� ��������� ���������� � ������
	for (int i = 0; i < list.size(); i++) {
		auto it = std::find(buf.begin(), buf.end(), list[i]);
		if (it != buf.end())
			alloc.push_back(i);
	}
	int needSize = box.width() -1; //������ ������ ������������� � ����
	//��������� + ��� �����
	for (int i = 0; i < list.size(); i++) {
		if (fs::is_directory(dir.filePath(list[i]) / list[i]))
			list[i] = "+ " + list[i];
	}
	//�������������� ������ �����
	for (int i = 0; i < list.size(); i++) {
		if (list[i].size() < needSize)
			list[i] += std::string(needSize - list[i].size(), ' ');
		else  if (list[i].size() > needSize)
			list[i].resize(needSize);
	}
	bool curBuf = false;
	//������������ �������� � ���� ������
	for (int i : alloc) {
		if (i != cur)
			list[i] = cBuf.string() + list[i] + cBack.string();
		else curBuf = true;
	}
	//������������ ��������� �������
	if (curBuf) {
		Color c(cCur.getBG(), cBuf.getFG());
		list[cur] = c.string() + list[cur] + cBack.string();
	}else
		list[cur] = cCur.string() + list[cur] + cBack.string();
}
Display& Display::Draw() {
	auto list = dir.getList(); //���� ����������� ��� ������
	if (!list.size()) {
		box.drawFillBox();
		return *this;
	} 
	int needSize = box.width() - 1; //������ ������ ������������� � ����
	Position x(box.getCurPoint());
	resizeList(list);
	cBack.colorize();
	//������� �������� �� �����
	int n = min(list.size(), pa); //���������� ������
	for (int i = pi; i < n; i++)
		x.printLn(list[i]);
	//������� ������ ������ ��� ������� ���������� ����������� �����
	n = (pa - pi + 1) - (n - pi + 1); //���������� ������
	for (int i = 0; i < n; i++)
		x.printLn(std::string(needSize, ' '));
	InfoFile info(dir.getPath() + "\\" + GetRegularFile());
	x.printLn(std::string(needSize, '-'))
		.printLn(std::string(needSize, ' '))
		.prevLine()
		.printLn(info.who())
		.printLn(std::string(needSize, ' '))
		.prevLine()
		.printLn(info.size());
	return *this;
}
Display& Display::DrawBorder() {
	box.drawBox();
	
	return *this;
}
Display& Display::reDraw() {
	box.drawBox(); //������������ �����
	DrawPath();
	Draw(); //�������������� ��� ��������
	
	return *this;
}
Display& Display::up() {
	bool change = false; //���� ������� ���������
	if (cur > 0){
		change = true;
		cur--;
		if (pi > cur) {
			pi--;
			pa--;
		}
	}	
	if (change) Draw();
	return *this;
}
Display& Display::down() {
	bool change = false;//���� ������� ���������
	if (cur < dir.size() - 1 ) {
		change = true;
		cur++;
		if (pa < cur + 1) {
			pa++;
			pi++;
		}
	}
	if (change) Draw();
	return *this;
}
fs::path Display::GetFullPathElement() {
	fs::path r = dir.filePath(GetRegularFile()) / fs::path(GetRegularFile());
	return r;
}