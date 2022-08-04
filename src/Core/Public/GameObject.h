//
// Created by acm on 04/08/2022.
//

#ifndef GAMEINC_GAMEOBJECT_H
#define GAMEINC_GAMEOBJECT_H

#include "Game.h"

class GameObject {
public:
    GameObject(const char* texturesheet, int xPos, int yPos);
    ~GameObject();

    void Update();
    void Render();

private:
    int xPos;
    int yPos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;


};


#endif //GAMEINC_GAMEOBJECT_H
