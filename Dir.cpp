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

void Dir::findByMask(const std::string mask) {
	std::string search = 
		(mask[0] == '*')? mask.substr(1): mask;
	list.clear();
	for (const auto& e : fs::recursive_directory_iterator(path)) {
		try {
			if (e.path().filename().string().find(search) != std::string::npos) {
				list[e.path().filename().string()] = e.path().parent_path();
			}
		} 
		catch(...) {// Пропускаем проблемные элементы}
		}
	
	}
}