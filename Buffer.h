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

	Buffer - хранит пути выделенных или 
		копированных объетов.

***************************************************/
#pragma once
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
namespace fs = std::filesystem;
class Buffer
{
private:
	std::set<fs::path> list;
	bool thenDelete = false;
public:
	Buffer(std::vector<std::string>& sList) {
		for (std::string& s : sList)
			list.insert(fs::path(s));
	}
	Buffer(std::vector<fs::path>& pathList) {
		for (fs::path& s : pathList)
			list.insert(s);  
	}
	Buffer() {}
	/*Добавляет элементы в буфер или удаляет элемент если он там уже есть*/
	Buffer& add(const fs::path& l);
	/*Добавляет элементы в буфер или удаляет элемент если он там уже есть*/
	inline Buffer& add(std::string& l) {return add(fs::path(l));}
	/*Удаляет элементы из буфера*/
	void remove(std::string& l) {remove(fs::path(l));}
	/*Удаляет элементы из буфера*/
	void remove(const fs::path& l);
	/*Проверяет наличие элемента в буфере*/
	bool include(const fs::path& l) {return list.find(l) != list.end();  }
	/*Очищает буфер*/
	inline void clear() {list.clear();}
	/*Возвращает список имен файлов в формате string*/
	std::vector<std::string> getFileNames();
	/*Возвращает список буфера в формате set<fs::path>*/
	inline std::set<fs::path> getPaths() { return list; }
	/*Устанавливает флаг удаления*/
	inline void setFlag(bool in) { thenDelete = in; }
	/*Получает значения флага удаления*/
	inline bool getFlag() { return thenDelete; }
};

