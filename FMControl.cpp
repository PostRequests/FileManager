#include "FMControl.h"
#include "Lib/KeyBoard/KeyBoard.h"
#include "MessBoxInfo.h"
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
        case KEY::DEL: delActiveBuf(); break;
        case KEY::F6: goTo(); break;
        case KEY::F7: changeDisk(); break;
        case KEY::ESCAPE: exitFM(); break;
        }
    } while (true);

}
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
    DownBoard::printDownBoard();
    return* this;
}
FMControl& FMControl::Enter() {
    if (!active->dir.size())
        return *this;
    bool change = false;
    fs::path curPath (active->dir.getPath() );
    fs::path curElem = active->GetRegularFile();
    fs::path newPath = ( curPath / curElem);
    try {
        if (fs::is_directory(newPath)) {
            active->dir.change(newPath);
            active->DrawPath();
            change = true;
        }
        else if (fs::is_regular_file(newPath)) {
            FileOpen::open(newPath);
        }
    }
    catch (...) {
        active->dir.change(curPath);
        MessBoxInfo mes ("В доступе отказано!");
        mes.show();
    }
    if (change) {
        active->reset();
    }
    return *this;
}
FMControl& FMControl::Up() {
    fs::path path;
    if (active->dir.isBlock()) {
        active->dir.unlock();
        path = fs::path(active->dir.getPath());
    }
    else 
        path = fs::path(active->dir.getPath()).parent_path();
    try {
         active->dir.change(path);
         active->DrawPath();
    }
    catch (...) {
        MessBoxInfo mes ("В доступе отказано!");
        mes.show();
        update();
    }
    active->reset(); //Сбрасывает параметры курсора и обновляет поле с файлами
    return *this;
}


FMControl& FMControl::newPage() {
    EnterBox box("Введите имя папки");
    std::string name = box.getString();
    fs::path dirPath = active->dir.getPath() / fs::path(name);
    if (!fs::exists(dirPath)) 
        fs::create_directory(dirPath);
    else {
        MessBoxInfo box2("Папка уже существует");
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
    EnterBox box("Введите имя файла");
    std::string name = box.getString();
    fs::path filePath = active->dir.getPath() / fs::path(name);
    if (!fs::exists(filePath)) 
        std::ofstream file(filePath);
    else {
        MessBoxInfo box2("Файл уже существует");
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
    if (active->dir.isBlock()) return *this; //Если виртуальная папка, ничего не выполняем
    if (!buf.getPaths().size()) return *this; //Если буфер пустой ничего не выполняем
    
    Paste p(active->dir.getPath());
    p.paste(buf.getPaths());
    if (buf.getFlag()) {
        DeleteFil p;
        p.deleteList(buf.getPaths());
    }
    buf.clear();
    update();
    return *this;
}
FMControl& FMControl::delActiveBuf() {
    if (!active->dir.buffer.size()) return *this; //Если буфер пуст ничего не делаем
    MessageBoxChoice cho("Уверенны что хотите удалить?");
    if (cho.get()) {
        DeleteFil p;
        p.deleteList(active->dir.buffer.getPaths());
    }
    update();
    return *this;
}
FMControl& FMControl::goTo() {
    EnterBox x;
    std::string path = x.getString();
    active->dir.change(path);
    draw();
    return *this;
}
void FMControl::exitFM() {
    MessageBoxChoice cho("Вы точно хотите выйти?");
    if (cho.get())
        exit(0);
    draw();
}
FMControl& FMControl::changeDisk() {
    ChangeDisk disc;
    active->dir.change(disc.disc());
    draw();
    return *this;
}