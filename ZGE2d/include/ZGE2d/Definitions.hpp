//
// Created by Victor Sago on 2018-01-14.
//

#ifndef ZGE2D_DEFINITIONS_HPP
#define ZGE2D_DEFINITIONS_HPP

#include <SDL2/SDL.h>

#define DEFAULT_MOVESPEED 4

namespace zge2d {

    const int defaultFPS 		= 60;
    const int minFPS            = 8;
    const int maxFPS            = 128;

    const int defaultWinWidth 	= 800;
    const int defaultWinHeight 	= 600;

    const SDL_Color defaultCompBackground 	= {64, 128, 255, SDL_ALPHA_OPAQUE};
    const SDL_Color defaultWinBackground 	= {15, 15, 15, SDL_ALPHA_OPAQUE};
    const SDL_Color defaultTextForeground 	= {0, 0, 0, SDL_ALPHA_OPAQUE};
    const SDL_Color defaultTransparency		= {0, 0, 0};
    const SDL_Color colorBlack				= {0, 0, 0, SDL_ALPHA_OPAQUE};
    const SDL_Color colorWhite				= {255, 255, 255, SDL_ALPHA_OPAQUE};
    const SDL_Color colorGrey1				= {128, 128, 128, SDL_ALPHA_OPAQUE};
    const SDL_Color colorGrey2				= {160, 160, 160, SDL_ALPHA_OPAQUE};
    const SDL_Color colorGrey3				= {192, 192, 192, SDL_ALPHA_OPAQUE};
    const SDL_Color colorGrey4				= {208, 208, 208, SDL_ALPHA_OPAQUE};
    const SDL_Color colorGrey5				= {215, 215, 215, SDL_ALPHA_OPAQUE};
    const SDL_Color colorGrey6				= {224, 224, 224, SDL_ALPHA_OPAQUE};
    const SDL_Color colorGrey7				= {231, 231, 231, SDL_ALPHA_OPAQUE};
    const SDL_Color colorRed				= {255, 0, 0, SDL_ALPHA_OPAQUE};
    const SDL_Color colorGreen				= {0, 255, 0, SDL_ALPHA_OPAQUE};
    const SDL_Color colorBlue				= {0, 0, 255, SDL_ALPHA_OPAQUE};
    const SDL_Color colorYellow				= {255, 255, 0, SDL_ALPHA_OPAQUE};
    const SDL_Color colorTurquoise			= {0, 255, 255, SDL_ALPHA_OPAQUE};
    const SDL_Color colorMagenta			= {255, 0, 255, SDL_ALPHA_OPAQUE};

    constexpr static double PI_D = 3.1415926535897932d;

    inline bool operator==(const SDL_Rect& a, const SDL_Rect& b) {
        return a.x == b.x && a.y == b.y && a.w == b.w && a.h == b.h;
    }

}

#endif //ZGE2D_DEFINITIONS_HPP
