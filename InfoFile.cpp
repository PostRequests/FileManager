#include "InfoFile.h"
std::string InfoFile::formatNum(uintmax_t size)  {
	std::string r(std::to_string(size));
	const int len = static_cast<int>(r.length());
	for (int i = len - 3; i > 0; i-=3)
			r.insert(i, " ");
	return r;
}
std::string InfoFile::size() {
	std::error_code ec;
	if (fs::is_directory(path)) {
		int count = 0;
		for (const auto& entry : fs::directory_iterator(path, ec))
			count++;
		if (ec) return ec.message();
		return "�������� " + std::to_string(count) + " ��������";
	}
	else if (fs::is_regular_file(path)) {
		const auto size = fs::file_size(path);
		return ("������: " + formatNum(size) + " bytes");
	}
	return " ";
}
std::string InfoFile::who() {
	if (fs::is_directory(path))
		return "�����";
	else if (fs::is_regular_file(path))
		return "����";
	return "���-�� ���";
}