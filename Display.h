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

	Display - выводит интерфейс файлового менеджера на экран
	содержит в себе буфер с выделенными файлами и текущим путем.

***************************************************/
#pragma once
#include "Dir.h"
#include "Lib/Box/Box.h"
#include "InfoFile.h"
#include "DownBoard.h"
class Display
{
private:
	int cur; //Текущий индекс элемента
	int pi; //Строка с которой начинается отображение на экране
	int pa; //Строка которой заканчивается отображение элементов
	int papa; //Сохраняет стартовые значения pa
	Box box; //Тупо чтоб нарисовать квадрат
	/** @brief Обрезает список до размера который войдет в строку */
	void resizeList(std::vector<std::string>& v);
	/*Рисует прямоугольную границу*/
	Display& DrawBorder();
	
public:
	Color cBack; //Оновной цвет фона
	Color cBuf; //Цвет выделенных в буфере элементов
	Color cCur; //Цвет выделенного элемента
	Dir dir; //Содержит путь текущей папке и содержание элементов
	Display(int x, int y, int x2, int y2, std::string path): box(x,y,x2,y2), 
		cur(0), pi(0), pa(y2 - y - 4),papa(y2 - y - 4), dir(path) {
		cCur.setColor(RedBG);
		cBack.setColor(CyanFG);
		cBuf.setColor(YellowFG);
	}
	Display(int x, int y, int x2, int y2) : Display(x, y, x2, y2,"c:\\" ) {	}
	Display(){
		Position dis;
		dis.setConsoleSize();
		*this = Display(1, 1, dis.getX(), dis.getY(), fs::current_path().string() );
	}
	/*Рисует путь к файлу*/
	Display& DrawPath();
	/*Выводит элементы внутри границ*/
	Display& Draw();
	/*Полностью перерисовывает все, считая границы*/
	Display& reDraw();
	/*Действия при нажатии клавиши вверх*/
	Display& up();
	/*Действия при нажатии клавиши вниз*/
	Display& down();
	/*Сбрасывает контрольные точки cur pi pa*/
	void reset();
	/*Возвращает имя текущего файла (string)*/
	inline std::string GetCur() {return dir.getList()[cur];	}
	/*Возвращает путь к файлу целиком с названием файла*/
	fs::path GetFullPathElement();
};

