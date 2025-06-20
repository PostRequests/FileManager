#include "MessageBoxChoice.h"
bool MessageBoxChoice::get() {
	bool r = false;
	Color c(RedBG);
	show(); 
	Position winSize; //������� ������� ������� ����
	winSize.setConsoleSize(); //����������� �������� ������� ����
	Position eBox(winSize.getX() / 2,
		winSize.getY() - winSize.getY() / 3 - 2); //��������� ������
	KEY key;
	while (true)
	{
		if (r)
			c.colorize();
		eBox.print(btn1 + "  ");
		c.reset();
		if (!r)
			c.colorize();
		eBox.print(btn2);
		c.reset();
		key = KeyBoard::getKey();
		if (key == KEY::LEFT or key == KEY::RIGHT)
			r = !r;
		else if (key == KEY::ENTER)
			return r;
		eBox.restart();
	}
	
}

void MessageBoxChoice::show() {
	Position winSize; //������� ������� ������� ����
	winSize.setConsoleSize(); //����������� �������� ������� ����
	Position sBox(winSize.getX() / 4,
		winSize.getY() / 3); //��������� ��������� ����
	Position eBox(winSize.getX() - winSize.getX() / 4,
		winSize.getY() - winSize.getY() / 3); //�������� ��������� ����
	Box box(sBox, eBox);
	box.drawBox(); //������� �������
	box.print(text);//������������ �����
}