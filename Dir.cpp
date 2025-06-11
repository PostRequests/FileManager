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
		list.push_back(pat.path().filename().string());
	return *this;
}