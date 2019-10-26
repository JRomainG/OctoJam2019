#pragma once

#include "Entity.hpp"
#include "raylib.h"
#include "GhostAction.hpp"
#include <cmath>

class Ghost:
    public Entity
{
public:
    Ghost(float x, float y, Texture2D& tileset);
    ~Ghost();

	virtual void draw();
    virtual void update(float dt);

    void setAcceleration(float angle, float amplitude);
    void doAction(GhostAction);

    float getVx();
    float getVy();

private:
    float dashAx = 0;
    float dashAy = 0;
    float ax = 0;
    float ay = 0;
    float vx = 0;
    float vy = 0;

    float dashCooldown = 0;

	Texture2D& tileset;
	Rectangle src;

    void updateAcceleration(float dt);
    void updateSpeed(float);
    void updateCooldown(float);

    void dash();
};
