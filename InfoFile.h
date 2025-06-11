#pragma once
#include "Buffer.h"
class InfoFile
{
private:
	fs::path path;

	std::string formatNum(uintmax_t size);
public:
	InfoFile(std::string p):path(p){}
	InfoFile(fs::path p) :path(p) {}

	std::string size();
	std::string who();
};

