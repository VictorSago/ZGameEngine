//
// Created by Victor Sago on 2018-01-14.
//

#include <utility>
#ifdef DEBUG_BUILD
    #include <sstream>
#endif

#include "GameEngine.hpp"
#include "Definitions.hpp"
#include "MovingSprite.hpp"

namespace zge2d {

MovingSprite::MovingSprite(SDL_Renderer* renderTarget, int x, int y, int w, int h, const std::string& imagePath, bool visibility)
                : Sprite(renderTarget, x, y, w, h, imagePath, visibility) {
    std::cout << "MovingSprite constructor 7." << std::endl;
    moveSpeed = DEFAULT_MOVESPEED;
    moveDirX = moveDirY = 0.0f;
}

MovingSprite::~MovingSprite() {
    std::cout << "MovingSprite destructor" << std::endl;
}

void MovingSprite::setMoveDir(double dirX, double dirY) {
	double m = sqrt(dirX * dirX + dirY * dirY);
	if (m != 0) {
		moveDirX = dirX / m;
		moveDirY = dirY / m;
	} else {
		moveDirX = moveDirY = 0;
	}
//	std::cout << "MovingSprite setMoveDir(" << dirX << ", " << dirY << ")" << std::endl;
//	std::cout << "MovingSprite moveDirX: " << moveDirX << " , moveDirY: " << moveDirY << std::endl;
}

double MovingSprite::setFaceDir(double angle) {
    if (angle < 0 || angle >= 360) {
        auto q = static_cast<int>(floor(angle / 360));
        double r = angle - q * 360;
        faceDir = r;
    } else {
        faceDir = angle;
    }
//    std::cout << "MovingSprite setFaceDir(" << angle << ")" << std::endl;
//    std::cout << "MovingSprite faceDir: " << faceDir << std::endl;
    return faceDir;
}

double MovingSprite::setFaceDir(double dirX, double dirY) {
    double angle;
    if (dirX == 0 && dirY == 0) {
        angle = 0;
    } else {
        angle = atan2(dirY, dirX) * 180 / PI_D1;
    }
    if (dirX < 0) {
        flip = SDL_FLIP_VERTICAL;
    } else {
        flip = SDL_FLIP_NONE;
    }
    setFaceDir(angle);
//    std::cout << "MovingSprite setFaceDir(" << dirX << ", " << dirY << ")" << std::endl;
//    std::cout << "MovingSprite faceDir: " << faceDir << std::endl;
    return faceDir;
}

void MovingSprite::setFlip(SDL_RendererFlip f) {
    flip = f;
}

void MovingSprite::move() {
    boundingRect.x += moveSpeed * moveDirX;
    boundingRect.y += moveSpeed * moveDirY;
}

void MovingSprite::update() {
//    if(collisionHandler) {
//        handleCollisions();
//    }
    move();
    animate();
//    std::cout << "CropRect: {" << cropRect.x << ", " << cropRect.y << ", " << cropRect.w << ", " << cropRect.h << "}\n";
//    std::cout << "BoundingRect: {" << boundingRect.x << ", " << boundingRect.y << ", " << boundingRect.w << ", " << boundingRect.h << "}\n";
}

//void MovingSprite::update(float deltaTime) {
//    update(deltaTime, true);
//}


void MovingSprite::draw(SDL_Renderer* renderTarget) const {
    if (visible) {
        texture.get()->draw(renderTarget, &cropRect, &boundingRect);
    }
}

/*
void MovingSprite::draw() {
    if (visible) {
        SDL_RenderCopyEx(renderTarget, texture, &cropRect, &boundingRect, faceDir, NULL, flip);
    }
}
*/

//void MovingSprite::update(float deltaTime, bool active) {
//    //std::cout << "MovingSprite: update()\n";
//    if (!alwaysActive) {
//        isActive = active;
//    }
//    move(deltaTime);
//    if (isActive) {
//        animate(deltaTime);
//    } else {
//        frameCounter = 0;
//        cropRect.x = cropRect.w;
//    }
//}

//bool MovingSprite::intersectsWith(BasicSprite& s) {
//    bool collision = true;
//    if (this == &s) {
//        return false;
//    }
//    SDL_Rect otherPos = s.getPositionRect();
//    if(positionRect.x + positionRect.w < otherPos.x || positionRect.x > otherPos.x + otherPos.w ||
//       positionRect.y + positionRect.h < otherPos.y || positionRect.y > otherPos.y + otherPos.h) {
//        collision = false;
//    }
//
//    if (collision)
//        std::cout << "CollisionRect: " << collision << "\n";
//    return collision;
//}
//
//bool MovingSprite::intersectsWithCirc(BasicSprite& s) {
//    bool collision = false;
//    if (this == &s) {
//        return false;
//    }
//    SDL_Rect otherPos = s.getPositionRect();
//    int x1 = positionRect.x + positionRect.w / 2;
//    int x2 = otherPos.x + otherPos.w / 2;
//    int y1 = positionRect.y + positionRect.h / 2;
//    int y2 = otherPos.y + otherPos.h / 2;
//    float r1 = (positionRect.w/2.0f + positionRect.h/2.0f) / 2.0f;
//    float r2 = (otherPos.w/2.0f + otherPos.h/2.0f) / 2.0f;
//    if (std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2)) < (r1 + r2)) {
//        collision = true;
//    }
//    if (collision)
//        std::cout << "CollisionCirc: " << collision << "\n";
//    return collision;
//}

#ifdef DEBUG_BUILD
std::string MovingSprite::toString() {
    std::string c (", ");
    std::stringstream ss;
    ss << Sprite::toString();
    ss << "moveSpeed: " << moveSpeed << c << "moveDir: {" << moveDirX << c << moveDirY << "} ";
    return ss.str();
}
#endif

} // namespace
