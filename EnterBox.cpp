#include "EnterBox.h"
std::string EnterBox::getString() {
	std::string r;
	Position x;
	x.setConsoleSize();
	Box box(2, x.getY() / 2 - 2, x.getX() -2, x.getY() / 2 );
	box.drawBox();
	x = box.getCurPoint();
	x.prevLine()
		.printLn(head)
		.print(" :");
	std::getline(std::cin, r);
	return r;
}