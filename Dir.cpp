#include "Dir.h"
Dir& Dir::change(const std::string& path) {
	fs::path p (path);
	if (fs::is_directory(p)) {
		this->path = p;
		fill();
	}
	return *this;
}

Dir& Dir::fill() {
	list.clear();
	for (auto pat : fs::directory_iterator(path)) 
		list[pat.path().filename().string()] = path;
	return *this;
}

std::vector<std::string> Dir::getList() {
	std::vector<std::string> r;
	std::for_each(list.begin(), list.end(), [&](auto& i) {
		r.push_back(i.first);
		});
	return r;
}