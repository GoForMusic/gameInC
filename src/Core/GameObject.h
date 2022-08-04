//
// Created by acm on 04/08/2022.
//

#ifndef GAMEINC_GAMEOBJECT_H
#define GAMEINC_GAMEOBJECT_H

#include "Game.h"

class GameObject {
public:
    GameObject(const char* texturesheet, SDL_Renderer* ren);
    ~GameObject();

    void Update();
    void Render();

private:
    int xPos;
    int yPos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;


};


#endif //GAMEINC_GAMEOBJECT_H
