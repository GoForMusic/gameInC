//
// Created by acm on 04/08/2022.
//

#ifndef GAMEINC_TEXTUREMANAGER_H
#define GAMEINC_TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {

public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};


#endif //GAMEINC_TEXTUREMANAGER_H
