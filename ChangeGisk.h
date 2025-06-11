#pragma once
#include <vector>
#include <iostream>
#include <filesystem>
#include "Lib/Menu/Menu.h"
namespace fs = std::filesystem;
class ChangeDisk
{
private:
	std::vector<fs::path> disk;
public:
	ChangeDisk() { SkaNDisc(); }
	void SkaNDisc();
	fs::path disc();
};

