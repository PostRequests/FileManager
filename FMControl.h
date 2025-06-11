#pragma once
#include "Display.h"
#include "EnterBox.h"
class FMControl
{
	Display dis1; //Окно 
	Display dis2;//Окно 
	Display* active; // Активное окно

	/*Переключается между активными окнами TAB*/
	FMControl& swichActive();
	/*Переходит в выбранную папку ENTER*/
	FMControl& Enter();
	/*Переход на уровень выше BACKSPACE*/
	FMControl& Up();
	/*Создает папку F2*/
	FMControl& newPage();
	/*Обновляет после изменений или перехода в папке*/
	FMControl& update();
	/*Выводит информацию о горячих клавишах F1*/
public:
	FMControl(): active(&dis1){
		Position x;
		x.setConsoleSize();
		dis1 = Display(1, 1, x.getX() / 2, x.getY() - 2);
		dis2 = Display(x.getX() / 2 + 1, 1, x.getX(), x.getY() - 2);
		dis2.cCur = Color(BlackBG);
	}
	/*Запуск управления файловым менеджером*/
	void run();
	/*Перерисовывает все окна*/
	FMControl& draw();
};

