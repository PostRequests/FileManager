#include "MessageBoxChoice.h"
bool MessageBoxChoice::get() {
	bool r = false;
	Color c(RedBG);
	show(); 
	Position winSize; //Создаем позицию размера окна
	winSize.setConsoleSize(); //Присваиваем значения размера окна
	Position eBox(winSize.getX() / 2,
		winSize.getY() - winSize.getY() / 3 - 2); //Положение кнопок
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