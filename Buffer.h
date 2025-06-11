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
	/*��������� �������� � ����� ��� ������� ������� ���� �� ��� ��� ����*/
	Buffer& add(const fs::path& l);
	/*��������� �������� � ����� ��� ������� ������� ���� �� ��� ��� ����*/
	inline Buffer& add(std::string& l) {return add(fs::path(l));}
	/*������� �������� �� ������*/
	void remove(std::string& l) {remove(fs::path(l));}
	/*������� �������� �� ������*/
	void remove(const fs::path& l);
	/*��������� ������� �������� � ������*/
	bool include(const fs::path& l) {return list.find(l) != list.end();  }
	/*������� �����*/
	inline void clear() {list.clear();}
	/*���������� ������ ���� ������ � ������� string*/
	std::vector<std::string> getFileNames();
	/*���������� ������ ������ � ������� set<fs::path>*/
	inline std::set<fs::path> getPaths() { return list; }
	/*������������� ���� ��������*/
	inline void setFlag(bool in) { thenDelete = in; }
	/*�������� �������� ����� ��������*/
	inline bool getFlag() { return thenDelete; }
};

