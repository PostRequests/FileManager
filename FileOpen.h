#pragma once
#include <filesystem>
#include <windows.h>
namespace fs = std::filesystem;
class FileOpen
{
public:
	static void open(const fs::path& filePath);
};

