#pragma once
#include "Node.hpp"

class Entity: public Node {
public:
	Entity(float x, float y, float w, float h);
    ~Entity();
    // Perform render operation
    virtual void draw() override;
    // Perform update and logic
    virtual void update(float dt) override;

    // Reposition entity to a give x and y
    void setPosition(float x, float y);
    // Reposition entity by giving an offset
    void move(float dx, float dy);

	// x getter
	float getX() { return x; }
	// y getter
	float getY() { return y; }
	// w getter
	float getW() { return w; }
	// h getter
	float getH() { return h; }

protected:
    float x;
    float y;
	float w;
	float h;
};
