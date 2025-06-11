#pragma once
#include "Dir.h"
class CreateDir
{
private:
	fs::path path;
public:
	CreateDir(fs::path& path) : path(path) {}
	CreateDir(std::string& path) : path(path) {}
	CreateDir() : path(fs::current_path()) {}
	void create(std::string& name);
};

