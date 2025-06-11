#pragma once
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
namespace fs = std::filesystem;
class Buffer
{
private:
	std::vector<fs::path> list;
	bool thenDelete = false;
public:
	Buffer(std::vector<std::string>& sList) {
		for (std::string& s : sList)
			list.push_back(fs::path(s));
	}
	Buffer(std::vector<fs::path>& list) : list(list) {}
	Buffer() {}

	inline void add(std::vector<fs::path>& l) {
		for(auto el: l)
			list.push_back(el);
	}
	inline void add(std::vector<std::string>& l) {
		for (std::string& s : l)
			list.push_back(fs::path(s));
	}
	inline void add(fs::path& l) {
		list.push_back(l);
	}
	inline void add(std::string& l) {
		list.push_back(fs::path(l));
	}
	void remove(std::string& l) {
		remove(fs::path(l));
	}
	void remove(const fs::path& l) {
		auto re = std::find(list.begin(), list.end(), l);//Итератор на удаление
		if (re != list.end())
			list.erase(re);
	}
	bool include(const fs::path& l) {
		return std::find(list.begin(), list.end(), l) != list.end();
	}
	inline void clear() {
		list.clear();
	}
};

