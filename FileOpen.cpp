#include "FileOpen.h"
void FileOpen::open(const fs::path& filePath) {
    if (!fs::exists(filePath)) return;
    // Преобразуем путь в строку для WinAPI
    std::wstring widePath = filePath.wstring();
    // Открываем файл с ассоциированной программой
    HINSTANCE result = ShellExecuteW(
        NULL,                   // Без родительского окна
        L"open",                // Действие "open" (можно также "explore" для папок)
        widePath.c_str(),       // Путь к файлу
        NULL,                   // Параметры командной строки (если нужны)
        NULL,                   // Рабочий каталог
        SW_SHOWNORMAL           // Режим отображения окна
    );

}