#include "src/Core/Public/Game.h"

Game *game = nullptr;

int main(int argc, char* args[])
{
    //FPS limit
    const int FPS = 60;
    const int frameDelay=1000/FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("GameEnigne",800,600, false);

    while (game->running()){

        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay>frameTime){
            SDL_Delay(frameDelay-frameTime);
        }
    }
    game->clean();
    return 0;
}