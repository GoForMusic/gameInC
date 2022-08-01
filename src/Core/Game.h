//
// Created by acm on 01/08/2022.
//

#ifndef GAMEINC_GAME_H
#define GAMEINC_GAME_H

#include "SDL.h"
#include <iostream>

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int xPos,int yPos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() {return isRunning;}
private:
    int cnt=0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif //GAMEINC_GAME_H
