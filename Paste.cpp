#include "Paste.h"
void Paste::paste(std::vector<fs::path> BufferList) {
	for (auto el : BufferList) {
		if (fs::exists(el))
			if (fs::is_directory(el))
				fs::copy(el, path, fs::copy_options::recursive);
			else if (fs::is_regular_file(el)) 
				fs::copy(el, path);
	}
}