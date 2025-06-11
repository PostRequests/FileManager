#pragma once
#include "Display.h"
#include "EnterBox.h"
class FMControl
{
	Display dis1; //���� 
	Display dis2;//���� 
	Display* active; // �������� ����

	/*������������� ����� ��������� ������ TAB*/
	FMControl& swichActive();
	/*��������� � ��������� ����� ENTER*/
	FMControl& Enter();
	/*������� �� ������� ���� BACKSPACE*/
	FMControl& Up();
	/*������� ����� F2*/
	FMControl& newPage();
	/*��������� ����� ��������� ��� �������� � �����*/
	FMControl& update();
	/*������� ���������� � ������� �������� F1*/
public:
	FMControl(): active(&dis1){
		Position x;
		x.setConsoleSize();
		dis1 = Display(1, 1, x.getX() / 2, x.getY() - 2);
		dis2 = Display(x.getX() / 2 + 1, 1, x.getX(), x.getY() - 2);
		dis2.cCur = Color(BlackBG);
	}
	/*������ ���������� �������� ����������*/
	void run();
	/*�������������� ��� ����*/
	FMControl& draw();
};

