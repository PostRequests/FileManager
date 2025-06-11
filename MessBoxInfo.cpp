#include "MessBoxInfo.h"
void MessBoxInfo::show() {
	Position winSize; //������� ������� ������� ����
	winSize.setConsoleSize(); //����������� �������� ������� ����
	Position sBox(winSize.getX() / 4, 
		winSize.getY() / 3); //��������� ��������� ����
	Position eBox(winSize.getX() - winSize.getX() / 4,
		winSize.getY() - winSize.getY() / 3); //�������� ��������� ����
	Box box(sBox, eBox);
	box.drawBox(); //������� �������
	box.print(text);//������������ �����
	system("pause>null");
}