
#include <iostream>
#include "FMControl.h"
#include <Windows.h>
#include "EnterBox.h"
#include "InfoBox.h"
int main()
{
    
   /* while (true)
    {
        int key = _getch();
        if (key == 0 || key == 0xE0) 
            key = _getch();
        std::cout << key << " ";
    }*/
    system("chcp 1251>nul");
    FMControl a;
    a.run();
    system("pause>nul");
}

