//
// Created by Victor Sago on 2018-01-11.
//

#ifndef ZGE2D_LABEL_HPP
#define ZGE2D_LABEL_HPP

#include <string>
#include "VisComp.hpp"
#include "Texture.hpp"

namespace zge2d {

class Label : VisComp {
    private:
        std::string labelText;
        Texture* texture;
    public:
        Label(int x, int y, int w, int h, bool visibility);
        Label(const SDL_Rect& r, bool visibility = true);

};

}

#endif //ZGE2D_LABEL_HPP
