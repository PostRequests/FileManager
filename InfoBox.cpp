#include "InfoBox.h"
void InfoBox::show() {
	std::string keys;
	for (auto key : KeyInfo)
		keys += key;
	x.drawBox()
		.print(text)
		.print(keys);
	
	system("pause>nul");
	system("cls");
}