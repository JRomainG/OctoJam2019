#pragma once
#include "Animation.hpp"
#include <vector>
#include "Node.hpp"
#include <map>

class AnimationManager :
    public Node
{
public:
    AnimationManager();
	void addAnimation(int idx, std::vector<int> frames, float period, bool repeat);
    virtual void update(float dt) override;
    virtual void draw() override;
    int getFrame();
private:
    int current;
    std::map<int, Animation> animations;
};