#include "CreateDir.h"
void CreateDir::create(std::string& name) {
	fs::path newDir = path / fs::path(name);
	fs::create_directory(newDir);
}