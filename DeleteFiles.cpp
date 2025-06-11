#include "DeleteFiles.h"
void DeleteFil::deleteList(const std::set<fs::path>& list) {
	try {
		for (auto el : list) {
			if (fs::exists(el))
				if (fs::is_directory(el))
					fs::remove_all(el);
				else if (fs::is_regular_file(el))
					fs::remove(el);
		}
	}
	catch (...) {
		MessageBoxInfo e("�� ������� ������� ��������� �����, ��������� �� ������������ �� ��� ����� ������� �����������");
	}
}