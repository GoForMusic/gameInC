//
// Created by acm on 04/08/2022.
//

#ifndef GAMEINC_TEXTUREMANAGER_H
#define GAMEINC_TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {

public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);
private:

};


#endif //GAMEINC_TEXTUREMANAGER_H
