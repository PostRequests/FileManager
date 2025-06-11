#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
class Position
{
private:
	int x; //ѕозици€ х
	int y; //ѕозици€ у
	int startX; //ѕозици€ х изначальна€
	int startY; //ѕозици€ у изначальна€
public:
	Position() : x(1), y(1), startX(1), startY(1) {}
	Position(const Position& o) : Position(o.x, o.y) {}
	Position(int x, int y) : x(x), y(y), startX(x), startY(y) {}
	
	/// ”становка точки х без перехода
	Position& setX(int x);
	/// ”становка точки у без перехода
	Position& setY(int y);
	/// ”становка точки без перехода
	Position& setPos(const Position& o);
	/// ”становка точки без перехода
	inline Position& setPos(int x, int y) { return setPos(Position(x, y)); }
	/// ѕереход по сохраненным координатам
	Position& go();
	/// ѕереход и сохранение новых координат
	Position& goTo(const Position& o);
	/// ѕереход и сохранение новых координат
	Position& goTo(int x, int y);
	/// ѕереход и сохранение новых координат
	inline Position& goTo() { return goTo(*this); }
	/// ѕечатает на экране текущие координаты
	inline void show() { std::cout << "[x:" << x << ",y:" << y << "]\n"; }
	/// ѕечатает на экране текущие координаты в указанном месте
	Position& show(int x, int y);
	/// ƒобавл€ет у + 1, без перехода
	Position& nextLine(int line = 1);
	/// ќтнимает у 1 1, без перехода
	Position& prevLine(int line = 1);
	/// ƒобавл€ет у + 1, без перехода
	inline void operator++() { nextLine(); }
	/// ƒобавл€ет у + 1, без перехода
	inline void operator+=(int x) { nextLine(x); }
	/// ƒобавл€ет у - 1
	inline void operator--() { prevLine(); }
	/// ƒобавл€ет у - 1
	inline void operator-=(int x) { prevLine(x); }
	inline bool operator==(Position a) { return ((a.x == x && a.y == y) ? true : false); }
	/// ѕереходит по сохраненным координатам и печатает текст
	Position& print(const std::string& s);
	/// ѕереходит по сохраненным координатам и печатает текст, в конце переход на следующий уровень
	Position& printLn(const std::string& s);
	/// ѕереходит по сохраненным координатам и печатает текст, в конце переход на следующий уровень
	Position& printLn(const char s);
	///  ”станавливает координаты в точку размера консоли
	Position& setConsoleSize();
	/// ¬озвращает координаты по х
	inline int getX() { return x; }
	/// ¬озвращает координаты по у
	inline int getY() { return y; }
	// возвращает изначально установленную координату х
	inline int getMinX() { return startX; }
	// возвращает изначально установленную координату у
	inline int getMinY() { return startY; }
	Position& setStartX(int x);
	Position& setStartY(int y);
	/// ¬озвращение к первоначальным координатам
	Position& restart();
	//ѕеремещает курсор в указанную позицию
	inline static void moveTo(int x, int y) { std::cout << "\033[" << y << ";" << x << "H"; }
	//ƒобавл€ет к х определенное количество точек
	Position& plusX(int x);
	//ƒобавл€ет к у определенное количество точек
	Position& plusY(int y);
};

