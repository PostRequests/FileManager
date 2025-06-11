#pragma once
#include "MessageBoxInfo.h"
#include "Lib/KeyBoard/KeyBoard.h"
#include <iostream>
#include <string>
#include <windows.h>

class MessageBoxChoice : public MessageBoxInfo
{
private:
    std::string btn1;
    std::string btn2;
public:
    MessageBoxChoice(std::string text, std::string b1, std::string b2)
        : MessageBoxInfo(text), btn1(b1), btn2(b2) {
    }
    MessageBoxChoice(std::string text)
        : MessageBoxChoice(text, "��", "���") {
    }

    bool get();
};