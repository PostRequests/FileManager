#include "Buffer.h"
void Buffer::remove(const fs::path& l) {
	auto it = list.find(l);
	if (it != list.end())
		list.erase(it);
}
Buffer& Buffer::add(const fs::path& l) {
	if (!include(l))
		list.insert(l);
	else
		remove(l);
	return *this;
}
std::vector<std::string> Buffer::getFileNames() {
	std::vector<std::string> r;
	for (fs::path p: list)
		r.push_back(p.filename().string());
	return r;
}