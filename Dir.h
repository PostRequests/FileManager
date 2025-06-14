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
#include <algorithm>
#include <string>
#include <conio.h>
#include <vector>
#include <fstream>
#include "Buffer.h"
#include <map>
namespace fs = std::filesystem;
class Dir
{
private:
	fs::path path; //Путь к текущей папке
	std::map<std::string, fs::path> list; //Хранит список название файла: путь до файла
	bool virt = false; //Является ли папка виртуальной
	
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
	/*Изменить текущий путь, сканирует список фалов*/
	inline Dir& change(const fs::path& path) { return change(path.string()); };
	/*Возвращает текущий путь в формате string*/
	inline std::string getPath() { return path.string(); }
	/*возвращает путь к файлу*/
	inline fs::path filePath(std::string n) { return list[n]; }
	/*Возвращает список файлов текущего пути*/
	std::vector<std::string> getList();
	/*Возвращает количество элементов текущего пути*/
	inline int size() { return list.size(); }
	/*Заполняет мап элементами*/
	Dir& fill();
	/*Проверяем, находиться ли директория в заблокированном пространстве от вставки*/
	inline bool isBlock() { return virt; }
	/*Блокируем при переходе в виртуальную папку*/
	inline void block() { virt = true; }
	/*Разблокируем в нормальное состояние*/
	inline void unlock() { virt = true; }
	/*производить поиск по маске (с поиском по подпапкам) */
	void findByMask(const std::string mask);
};

