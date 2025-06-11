#pragma once
#include "Dir.h"
#include "Lib/Box/Box.h"
#include "InfoFile.h"
#include "DownBoard.h"
class Display
{
private:
	int cur;
	int pi;
	int pa;
	int papa;
	Box box;
	/** @brief Обрезает список до размера который войдет в строку */
	void resizeList(std::vector<std::string>& v);
public:
	Color cBack; //Оновной цвет фона
	Color cBuf; //Цвет выделенных в буфере элементов
	Color cCur; //Цвет выделенного элемента
	Dir dir;
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
	Display& DrawBorder();
	Display& Draw();
	Display& reDraw();
	Display& up();
	Display& down();
	void reset() { cur = 0; 
	pi = 0;
	pa = papa;
	}

	inline std::string GetCur() {return dir.getList()[cur];	}
	fs::path GetFullPathElement();
};

