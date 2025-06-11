/***************************************************
        ╔══════════════════════════════════╗
        ║      ЭКЗАМЕНАЦИОННАЯ РАБОТА      ║
        ╠══════════════════════════════════╣
        ║ Ученик академии "TOP"            ║
        ║ Группа: ВПД 411                  ║
        ║ Бородин Сергей Викторович        ║
        ╠══════════════════════════════════╣
        ║ Тема: Файловый менеджер на C++   ║
        ║                                  ║
        ╚══════════════════════════════════╝

    MessageBoxChoice - Выводит на экран диалоговое
        меню, содержит кнопки ДА и НЕТ, возвращает
        результат нажатой кнопки


***************************************************/

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
    /*Выводит диалоговое окно на экран, возвращает результат выбора*/
    bool get();
    /*Выводит диалоговое окно на экран*/
    void show();
};