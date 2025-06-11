#pragma once
#include <iostream>
#include <filesystem>
#include <string>
#include <conio.h>
#include <vector>
#include <fstream>
namespace fs = std::filesystem;
class Dir
{
private:
	fs::path path;
	std::vector<std::string> list;
public:
	Dir(): path(fs::current_path()) { fill(); }
	Dir(std::string path) {
		std::error_code er;
		if (fs::is_directory(path)) 
			this->path = path;
		else 
			this->path = "C:";
		fill();
	}
	Dir& change(const std::string& path);
	inline Dir& change(const fs::path& path) { return change(path.string()); };
	inline std::string getPath() { return path.string(); }
	inline std::vector<std::string> getList() { return list; }
	/*Возвращает количество элементов текущего пути*/
	inline int size() { return list.size(); }
	Dir& fill();
};

