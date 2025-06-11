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
    bool change = false;
    fs::path curPath (active->dir.getPath() );
    fs::path curElem = active->GetCur();
    fs::path newPath = ( curPath / curElem);
    try {
        if (fs::is_directory(newPath)) {
            active->dir.change(newPath);
            change = true;
        }
    }
    catch (...) {
        active->dir.change(curPath);
        MessageBoxInfo mes ("В доступе отказано!");
        mes.show();
    }
    if (change) {
        active->reset();
        draw();
    }
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
        case KEY::F2: rename(); break;
        case KEY::F3: newPage(); break;
        case KEY::F4: newFile(); break;
        case KEY::F5: update(); break; 
        case KEY::SPACE: collectFiles(); break;
        case KEY::F1: InfoBox(); draw(); break;
        case KEY::C: addBuffer(false); break;
        case KEY::X: addBuffer(true); break;
        case KEY::V: paste(); break;
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
    active->dir.buffer.clear();
    active->reset();
    active->dir.fill();
    draw();
    return *this;
}
FMControl& FMControl::rename() {
    fs::path re (active->dir.getPath());
    EnterBox x;
    std::string s = x.getString();
    fs::path newNamePath = re / s;
    fs::rename(active->GetFullPathElement(), newNamePath);
    update();
    return *this;
}
FMControl& FMControl::newFile() {
    EnterBox box;
    std::string name = box.getString();
    fs::path filePath = active->dir.getPath() / fs::path(name);
    if (!fs::exists(filePath)) {
        std::ofstream file(filePath);
    }
    else {
        MessageBoxInfo box2("Файл уже существует");
        box2.show();
    }
    update();
    return *this;
}

FMControl& FMControl::collectFiles() {
    fs::path p = active->GetFullPathElement();
    active->dir.buffer.add(p);
    active->Draw();
    return *this;
}
FMControl& FMControl::addBuffer(bool del) {
    this->buf = active->dir.buffer;
    this->buf.setFlag(del);
    active->dir.buffer.clear();
    draw();
    return *this;
}
FMControl& FMControl::paste() {
    if (!buf.getPaths().size()) return *this; //Если буфер пустой ничего не выполняем
    Paste p(active->dir.getPath());
    p.paste(buf.getPaths());
    buf.clear();
    update();
    return *this;
}