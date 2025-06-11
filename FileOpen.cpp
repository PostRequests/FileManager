#include "FileOpen.h"
void FileOpen::open(const fs::path& filePath) {
    if (!fs::exists(filePath)) return;
    // ����������� ���� � ������ ��� WinAPI
    std::wstring widePath = filePath.wstring();
    // ��������� ���� � ��������������� ����������
    HINSTANCE result = ShellExecuteW(
        NULL,                   // ��� ������������� ����
        L"open",                // �������� "open" (����� ����� "explore" ��� �����)
        widePath.c_str(),       // ���� � �����
        NULL,                   // ��������� ��������� ������ (���� �����)
        NULL,                   // ������� �������
        SW_SHOWNORMAL           // ����� ����������� ����
    );

}