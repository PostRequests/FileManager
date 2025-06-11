#include "MessBoxInfo.h"
void MessBoxInfo::show() {
	Position winSize; //Создаем позицию размера окна
	winSize.setConsoleSize(); //Присваиваем значения размера окна
	Position sBox(winSize.getX() / 4, 
		winSize.getY() / 3); //Стартовое положение окна
	Position eBox(winSize.getX() - winSize.getX() / 4,
		winSize.getY() - winSize.getY() / 3); //Конечное положение окна
	Box box(sBox, eBox);
	box.drawBox(); //Ритмуем квадарт
	box.print(text);//Отрисовываем текст
	system("pause>null");
}