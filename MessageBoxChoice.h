#pragma once
#include "MessBoxInfo.h"
#include "Lib/KeyBoard/KeyBoard.h"
#include <iostream>
#include <string>
#include <windows.h>

class MessageBoxChoice 
{
private:
    std::string text;
    std::string btn1;
    std::string btn2;
public:
    MessageBoxChoice(std::string text, std::string b1, std::string b2)
        : text(text), btn1(b1), btn2(b2) {
    }
    MessageBoxChoice(std::string text)
        : MessageBoxChoice(text, "Да", "Нет") {
    }

    bool get();
    void show();
};