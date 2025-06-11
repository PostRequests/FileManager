#pragma once
#include <string>
#include <functional>
#include "../Box/Box.h"
class MenuItem {
protected:
    std::string head;
    std::function<void()> enter;
    std::function<void()> move;

public:
    MenuItem()
        : head(""),  enter(nullptr), move(nullptr) {
    }
    MenuItem( const std::string& h, const std::function<void()>& e)
        : head(h), enter(e) {
    }
    MenuItem(const std::string& n, const std::function<void()>& e,
        const std::function<void()>& m)
        : head(n),  enter(e), move(m){
    }
    /**
     * @brief Краткое описание
     * ([тип] [имя])
     * @return описание
     */
    inline void setHead(const std::string& h) { head = h; }
    inline void setEnter(const std::function<void()>& e) { enter = e; };
    inline void setMove(const std::function<void()>& m) { move = m; };
    inline std::string& getHead() { return head; }

    inline void onEnter() {if (enter) enter();}
    inline void onMove() { if (move) move(); }
};

