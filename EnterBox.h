#pragma once
#include "MessageBoxInfo.h"
class EnterBox
{
private:
	std::string head;
public:
	EnterBox(const std::string& h) : head(h){}
	EnterBox() : EnterBox("¬вод") {}
	std::string getString();
};

