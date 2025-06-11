#pragma once
#include "Lib/Box/Box.h"
#include "FMControl.h"
class MessageBoxInfo
{
private:
	std::string text;
public:
	MessageBoxInfo(std::string text) : text(text){}
	MessageBoxInfo() : text("\tНеизвестная ошибка") {}
	void show();
};

