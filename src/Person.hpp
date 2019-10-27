#pragma once
#include "Entity.hpp"
#include "raylib.h"
#include "InteractionType.hpp"

typedef enum {
    calm,
    excited,
    entering,
    leaving,
    disabled
} PersonState;


class Person:
    public Entity
{
public:
    Person(float x, float y, Texture2D& tileset);
    ~Person();

    virtual void draw() override;
    virtual void update(float dt) override;
    void becomeExcited();
    void reactToInteraction(InteractionType);

    // Orders to leave the room
    void leave();
    // Orders to enter the room
    void enter();

    bool isDisabled() { return disabled; }
    PersonState getState();

protected:
	bool disabled = false;
    PersonState state = PersonState::calm;
	Rectangle src;
	Texture2D& tileset;

private:
    float fadeTimer = 0;
};
