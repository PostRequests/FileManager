#include "ChangeGisk.h"
void ChangeDisk::SkaNDisc() {
	disk.clear();
	std::error_code er;
	for (char i = 'A'; i <= 'Z'; i++){
		std::string t(1, i);
		t += ":\\";
		fs::path mb (t);
		if (fs::exists(mb, er))
			disk.push_back(mb);
		//if (er) std::cout << er.message() << '\n';
	}
}
fs::path ChangeDisk::disc() {
	SkaNDisc();
	Position pos;
	pos.setConsoleSize().setPos(pos.getX() / 2 - 2, pos.getY() / 2 - 4);
	Menu m(pos);
	for (auto d : disk) 
		m.addItem(d.string(), []() {});
	return disk[m.run(true)];
}