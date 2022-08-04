//
// Created by acm on 04/08/2022.
//

#ifndef GAMEINC_ECS_H
#define GAMEINC_ECS_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>



class Component;
class Entity;

using namespace std;
using ComponentID = size_t;

inline ComponentID getComponentID(){
    static ComponentID lastID = 0;
    return lastID++;
};

template <typename T> inline ComponentID getComponentTypeID() noexcept{
    static ComponentID typeID = getComponentID();
    return typeID;
}

constexpr size_t maxComponents = 32;

using ComponentBitSet = bitset<maxComponents>;
using ComponentArray = array<Component*, maxComponents>;

class Component{
public:
    Entity* entity;

    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}
    virtual  ~Component(){}
};

class Entity
{
private:
    bool active = true;
    vector<unique_ptr<Component>> components;
    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
public:
    void update(){
        for(auto& c:components) c->update();
        for(auto& c: components) c->draw();
    }

    void draw(){}
    bool isActive() const {return active;}
    void destroy(){active= false;}

    template<typename T> bool hasComponent() const{
        return componentBitSet[getComponentTypeID<T>];
    }

    template<typename T, typename... TArgs> T& addComponent(TArgs&&... mArgs){
        T* c(new T(forward<TArgs>(mArgs)...));
        c->entity = this;
        unique_ptr<Component> uPtr{c};
        components.emplace_back(move(uPtr));

        componentArray[getComponentTypeID<T>()] = c;
        componentBitSet[getComponentTypeID<T>()] = true;

        c->init();
        return *c;
    }

    template<typename T> T& getComponenet() const{
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
};

class Manager
{
private:
    vector<unique_ptr<Entity>> entities;

public:
    void update(){
        for(auto& e : entities) e->update();
    }
    void draw(){
        for(auto& e: entities) e->draw();
    }

    void refresh(){
        entities.erase(remove_if(begin(entities), end(entities),[](const unique_ptr<Entity> &mEntity){
            return !mEntity->isActive();
        }), end(entities));
    }

    Entity& addEntity()
    {
        Entity* e = new Entity();
        unique_ptr<Entity> uPtr{e};
        entities.emplace_back(move(uPtr));
        return *e;
    }
};

#endif //GAMEINC_ECS_H
