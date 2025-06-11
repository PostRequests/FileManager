#include "Display.h"
void Display::resizeList(std::vector<std::string>& list) {
	std::vector<std::string> buf = dir.buffer.getFileNames();
	std::vector<int> alloc;
	//Распределяем итераторы для перекрашивания элементов выделенных в буфере
	for (int i = 0; i < list.size(); i++) {
		auto it = std::find(buf.begin(), buf.end(), list[i]);
		if (it != buf.end())
			alloc.push_back(i);
	}
	int needSize = box.width() -1; //Ширина текста помещающегося в бокс
	//Подготавливаем размер строк
	for (int i = 0; i < list.size(); i++) {
		if (list[i].size() < needSize)
			list[i] += std::string(needSize - list[i].size(), ' ');
		else  if (list[i].size() > needSize)
			list[i].resize(needSize);
	}
	bool curBuf = false;
	//Раскрашиваем элементы в цвет буфера
	for (int i : alloc) {
		if (i != cur)
			list[i] = cBuf.string() + list[i] + cBack.string();
		else curBuf = true;
	}
	//Раскрашиваем выбранный элемент
	if (curBuf) {
		Color c(cCur.getBG(), cBuf.getFG());
		list[cur] = c.string() + list[cur] + cBack.string();
	}else
		list[cur] = cCur.string() + list[cur] + cBack.string();
}
Display& Display::Draw() {
	auto list = dir.getList(); //Лист необходимый для печати
	if (!list.size()) return *this;
	int needSize = box.width() - 1; //Ширина текста помещающегося в бокс
	Position x(box.getCurPoint());
	resizeList(list);
	cBack.colorize();
	//Выводим элементы на экран
	int n = min(list.size(), pa); //Количество циклов
	for (int i = pi; i < n; i++)
		x.printLn(list[i]);
	//Выводим пустые строки для очистки остального содержимого ранее
	n = (pa - pi + 1) - (n - pi + 1); //Количество циклов
	for (int i = 0; i < n; i++)
		x.printLn(std::string(needSize, ' '));
	InfoFile info(dir.getPath() + "\\" + GetCur());
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
	int needSize = box.width() - 1; //Ширина текста помещающегося в бокс
	Position x(box.getCurPoint().prevLine());
	std::string path = dir.getPath();
	path.resize(needSize);
	box.drawBox();
	x.printLn(path);
	Draw();
	
	return *this;
}
Display& Display::up() {
	bool change = false;
	if (cur != 0){
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
	bool change = false;
	if (cur != dir.size() - 1) {
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
	fs::path r = dir.getPath() / fs::path(GetCur());
	return r;
}