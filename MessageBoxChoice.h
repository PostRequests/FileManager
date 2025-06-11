#pragma once
#include "MessageBoxInfo.h"
#include <iostream>
#include <string>
class MessageBoxChoice
{
private:
	std::string text;
	std::string btn1;
	std::string btn2;
public:
	MessageBoxChoice(std::string text, std::string b1, std::string b2) : text(text), btn1(b1), btn2(b2){}
	MessageBoxChoice(std::string text) : MessageBoxChoice(text, "Да", "Нет"){}
};

