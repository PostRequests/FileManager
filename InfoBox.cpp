#include "InfoBox.h"
void InfoBox::show() {
	x.drawBox();
	x.print(text);
	system("pause>nul");
	system("cls");
}