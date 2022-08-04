//
// Created by acm on 04/08/2022.
//

#include "src/Core/Public/GameObject.h"
#include "src/Core/Public/TextureManager.h"

GameObject::GameObject(const char *texturesheet, int xPos, int yPos) {
    objTexture = TextureManager::LoadTexture(texturesheet);
    this->xPos=xPos;
    this->yPos=yPos;
}

GameObject::~GameObject() {

}

void GameObject::Update() {

    xPos++;
    yPos++;

    srcRect.h = 42;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x  = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h *2;
}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer,objTexture,&srcRect, &destRect);
}
