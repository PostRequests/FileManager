#include "FMControl.h"
#include "Lib/KeyBoard/KeyBoard.h"
#include "MessageBoxInfo.h"
FMControl& FMControl::swichActive() {
    active = (active == &dis1) ? &dis2 : &dis1;
    Display* passive = (active == &dis1) ? &dis2 : &dis1;
    active->cCur = Color(RedBG);
    passive->cCur = Color();
    active->Draw();
    passive->Draw();
    return *this;
}
FMControl& FMControl::draw() {
    dis1.reDraw();  
    dis2.reDraw();
    return* this;
}
FMControl& FMControl::Enter() {
    fs::path curPath (active->dir.getPath() );
    fs::path curElem = active->GetCur();
    fs::path newPath = ( curPath / curElem);
    try {
        if (fs::is_directory(newPath)) {
            active->dir.change(newPath);
        }
    }
    catch (...) {
        active->dir.change(curPath);
        MessageBoxInfo mes ("В доступе отказано!");
        mes.show();
    }
    active->reset();
    draw();
    return *this;
}
FMControl& FMControl::Up() {
    fs::path path = fs::path(active->dir.getPath()).parent_path() ;
    try {
         active->dir.change(path);
    }
    catch (...) {
        MessageBoxInfo mes ("В доступе отказано!");
        mes.show();
    }
    update();
    return *this;
}
void FMControl::run() {
    draw();
    KEY key;
    do {
        key = KeyBoard::getKey();
        switch (key) {
        case KEY::DOWN: active->down(); break;
        case KEY::UP: active->up(); break;
        case KEY::TAB: swichActive(); break;
        case KEY::ENTER: Enter(); break;
        case KEY::BACKSPACE: Up(); break;
        case KEY::F2: newPage(); break;
        }
    } while (true);
    
}

FMControl& FMControl::newPage() {
    EnterBox box;
    std::string name = box.getString();
    fs::path dirPath = active->dir.getPath() / fs::path(name);
    if (!fs::exists(dirPath)) {
        fs::create_directory(dirPath);
    }
    else {
        MessageBoxInfo box2("Папка уже существует");
        box2.show();
    }
    update();
    return *this;
}
FMControl& FMControl::update() {
    active->reset();
    active->dir.fill();
    draw();
    return *this;
}