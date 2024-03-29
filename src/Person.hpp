#pragma once
#include "Entity.hpp"
#include "raylib.h"
#include "InteractionType.hpp"
#include "AnimationManager.hpp"
#include "Spritesheet.hpp"

enum class PersonState {
    calm,
    excited,
    scared,
    entering,
    leaving,
    disabled
};

enum class PersonOrientation {
    top,
    down,
    left,
    right,
};


class Person:
    public Entity
{
public:
    Person(float x, float y, Texture2D& tileset, PersonOrientation orientation);
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
    PersonOrientation getOrientation();

protected:
	bool disabled = false;
    PersonState state = PersonState::calm;
    PersonOrientation orientation;
	Rectangle src;
	Texture2D& tileset;
	Spritesheet spritesheet;
	AnimationManager animationManager;
private:
    float fadeTimer = 0;
};
