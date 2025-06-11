/***************************************************
		╔══════════════════════════════════╗
		║      ЭКЗАМЕНАЦИОННАЯ РАБОТА      ║
		╠══════════════════════════════════╣
		║ Ученик академии "TOP"            ║
		║ Группа: ВПД 411                  ║
		║ Бородин Сергей Викторович        ║
		╠══════════════════════════════════╣
		║ Тема: Файловый менеджер на C++   ║
		║                                  ║
		╚══════════════════════════════════╝

	FMControl - Основной объект для запуска и управления
		файловым менеджером.

***************************************************/
#pragma once
#include "Display.h"
#include "EnterBox.h"
#include "InfoBox.h"
#include "Paste.h"
#include "DeleteFiles.h"
#include "FileOpen.h"
#include "MessageBoxChoice.h"
#include "ChangeGisk.h"
class FMControl
{
	Display dis1; //Окно 
	Display dis2;//Окно 
	Display* active; // Активное окно
	Buffer buf; //Буфер обмена

	/*Переключается между активными окнами TAB*/
	FMControl& swichActive();
	/*Переходит в выбранную папку ENTER*/
	FMControl& Enter();
	/*Переход на уровень выше BACKSPACE*/
	FMControl& Up();
	/*Создает папку F3*/
	FMControl& newPage();
	/*Обновляет после изменений или перехода в папке*/
	FMControl& update();
	/*Переименовывает текущий файл или папку F2*/
	FMControl& rename();
	/*Создает файл F4*/
	FMControl& newFile();
	/*Выделяет внутренний буфер SPACE*/
	FMControl& collectFiles();
	/**
	 * @brief Помещает в буфер скопированные или вырезанные значения
	 * @param del указывает будут ли удалены файлы после копирования
	 */
	FMControl& addBuffer(bool del);
	/*вставляет содержимое буфера */
	FMControl& paste();
	/*Удаляет файлы которые в данное время выбраны в активном окне*/
	FMControl& delActiveBuf();
	/*Переход в папку по прямой ссылке*/
	FMControl& goTo();
	/*Выход из программы, предварительно спрашивает*/
	void exitFM();
	/*Изменить корневой диск*/
	FMControl& changeDisk();
public:
	FMControl(): active(&dis1){
		Position x;
		x.setConsoleSize();
		dis1 = Display(1, 1, x.getX() / 2, x.getY() - 1);
		dis2 = Display(x.getX() / 2 + 1, 1, x.getX(), x.getY() - 1);
		dis2.cCur = Color(BlackBG);
	}
	/*Запуск управления файловым менеджером*/
	void run();
	/*Перерисовывает все окна*/
	FMControl& draw();
};

