#pragma once
#include "Display.h"
#include "EnterBox.h"
#include "InfoBox.h"
#include "Paste.h"
#include "DeleteFiles.h"
#include "FileOpen.h"
class FMControl
{
	Display dis1; //���� 
	Display dis2;//���� 
	Display* active; // �������� ����
	Buffer buf; //����� ������

	/*������������� ����� ��������� ������ TAB*/
	FMControl& swichActive();
	/*��������� � ��������� ����� ENTER*/
	FMControl& Enter();
	/*������� �� ������� ���� BACKSPACE*/
	FMControl& Up();
	/*������� ����� F3*/
	FMControl& newPage();
	/*��������� ����� ��������� ��� �������� � �����*/
	FMControl& update();
	/*��������������� ������� ���� ��� ����� F2*/
	FMControl& rename();
	/*������� ���� F4*/
	FMControl& newFile();
	/*�������� ���������� ����� SPACE*/
	FMControl& collectFiles();
	/**
	 * @brief �������� � ����� ������������� ��� ���������� ��������
	 * @param del ��������� ����� �� ������� ����� ����� �����������
	 */
	FMControl& addBuffer(bool del);
	/*��������� ���������� ������ */
	FMControl& paste();
	/*������� ����� ������� � ������ ����� ������� � �������� ����*/
	FMControl& delActiveBuf();
public:
	FMControl(): active(&dis1){
		Position x;
		x.setConsoleSize();
		dis1 = Display(1, 1, x.getX() / 2, x.getY() - 1);
		dis2 = Display(x.getX() / 2 + 1, 1, x.getX(), x.getY() - 1);
		dis2.cCur = Color(BlackBG);
	}
	/*������ ���������� �������� ����������*/
	void run();
	/*�������������� ��� ����*/
	FMControl& draw();
};

