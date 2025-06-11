#include "DownBoard.h"
void DownBoard::printDownBoard() {
	Position x;
	Color c(BlueBG, YellowFG);
	
	x.setConsoleSize();
	int xLimit = x.getX();
	x.setX(2);
	InfoBox ib(false);
	auto vectorKeys = ib.GetKeyInfo();
	for (int i = 0; i < vectorKeys.size(); i++)
	{
		if (xLimit < x.getX() + vectorKeys[i].size())
			break;
		c.colorize();
		x.print(vectorKeys[i]);
		c.reset();
		x.print(" ");
	}
}