#pragma once
#include "Buffer.h"
class Paste
{
private:
	fs::path path;
public:
	Paste(fs::path path): path(path){}
	Paste(std::string path) : path(path) {}
	Paste() : path(fs::current_path()) {}
	void paste(const std::set<fs::path>& BufferList);
};

