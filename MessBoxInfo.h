#pragma once
#include "Lib/Box/Box.h"
#include "FMControl.h"
class MessBoxInfo
{
private:
	std::string text;
public:
	MessBoxInfo(std::string text) : text(text){}
	MessBoxInfo() : text("\tНеизвестная ошибка") {}
	void show();
};

