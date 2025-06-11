#pragma once
#include <iostream>
#include <filesystem>
#include <string>
#include <conio.h>
#include <vector>
#include <fstream>
#include "Buffer.h"
namespace fs = std::filesystem;
class Dir
{
private:
	fs::path path;
	std::vector<std::string> list;
	
public:
	Buffer buffer;
	Dir(): path(fs::current_path()) , buffer(){ fill(); }
	Dir(std::string path): buffer() {
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
	/*���������� ���������� ��������� �������� ����*/
	inline int size() { return list.size(); }
	Dir& fill();
};

