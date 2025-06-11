/***************************************************
		╔══════════════════════════════════╗
		║      ЭКЗАМЕНАЦИОННАЯ РАБОТА      ║
		╠══════════════════════════════════╣
		║ Ученик академии "TOP"            ║
		║ Группа: ВПД 411                  ║
		║ Бородин Сергей Викторович        ║
		╠══════════════════════════════════╣
		║ Тема: Файловый менеджер на C++   ║
		║                                  ║
		╚══════════════════════════════════╝

	Dir - хранить путь к папке и содержимое.

***************************************************/
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
	/*Изменить текущий путь, сканирует список фалов*/
	Dir& change(const std::string& path);
	inline Dir& change(const fs::path& path) { return change(path.string()); };
	/*Возвращает текущий путь в формате string*/
	inline std::string getPath() { return path.string(); }
	/*Возвращает список файлов текущего пути*/
	inline std::vector<std::string> getList() { return list; }
	/*Возвращает количество элементов текущего пути*/
	inline int size() { return list.size(); }
	Dir& fill();
};

