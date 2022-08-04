//
// Created by acm on 01/08/2022.
//

#include "Game.h"

using namespace std;

SDL_Texture* playerTex;
SDL_Rect srcR, destR;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        cout<<"Subsystems Initialisez!..." << endl;
        window = SDL_CreateWindow(title,xPos,yPos, width,height, flags);
        if(window){
            cout<<"Window created!"<<endl;
        }

        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            cout<<"Renderer created!"<<endl;
        }
        isRunning= true;
    }else{
        isRunning= false;
    }

    SDL_Surface* tmpSurface = IMG_Load("../assets/player/player1.png");
    playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning= false;
            break;

        default:
            break;
    }
}

void Game::update() {
    cnt++;

    destR.h = 42;
    destR.w = 32;
    destR.x = cnt;

    cout<<cnt<<" ";
}

void Game::render() {
    SDL_RenderClear(renderer);
    //add stuff to render
    SDL_RenderCopy(renderer,playerTex,NULL,&destR);


    //~~~~~~
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout<<"Game Cleaned"<<endl;
}



