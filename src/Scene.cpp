#include "Scene.hpp"
#include "Constants.hpp"
#include <cstdlib>
#define _USE_MATH_DEFINES 
#include "math.h"

Scene::Scene() {};

Scene::~Scene() {
    // Release all the pointers we have
	for (auto node : nodes) {
		node.reset();
	}
	for (auto table : tables) {
		table.reset();
	}
	for (auto person : persons) {
		person.reset();
	}
};

void Scene::draw() {
    DrawFPS(10, 10);

    // Delegate drawing to all the nodes
    for (auto& node: nodes) {
        node->draw();
    }

    // Draw the ghost last so it's on top
    ghost.draw();
}

void Scene::update(float dt) {
    // Delegate updating to all the nodes
    for (auto& node: nodes) {
        node->update(dt);
    }

    // Draw the ghost last so it's on top
    ghost.update(dt);
}

float Scene::getInputAngle() {
    float angle = 0;

    if (IsGamepadAvailable(GAMEPAD_PLAYER1)) {
        // Joystick input
        float x = GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_AXIS_LEFT_X);
        float y = -GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_AXIS_LEFT_Y);
        angle = std::atan2(y, x);
    }

    if (IsGamepadAvailable(GAMEPAD_PLAYER1) && angle == 0) {
        // D-Pad as backup
        bool pressingRight = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
        bool pressingLeft = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_LEFT);
        bool pressingUp = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_UP);
        bool pressingDown = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_DOWN);
        angle = computeAngle(pressingLeft, pressingRight, pressingUp, pressingDown);
    }

    if (angle == 0) {
        // Keyboard as last hope
        bool pressingRight = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
        bool pressingLeft = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
        bool pressingUp = IsKeyDown(KEY_UP) || IsKeyDown(KEY_W);
        bool pressingDown = IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S);
        angle = computeAngle(pressingLeft, pressingRight, pressingUp, pressingDown);
    }

    return angle;
}

float Scene::getInputAmplitude() {
    float amplitude = 0;

    if (IsGamepadAvailable(GAMEPAD_PLAYER1)) {
        // Joystick input
        float xAccel = GHOST_ACCEL * GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_AXIS_LEFT_X);
        float yAccel = GHOST_ACCEL * GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_AXIS_LEFT_Y);
        amplitude = std::sqrt(std::pow(xAccel, 2) + std::pow(yAccel, 2));
    }

    if (IsGamepadAvailable(GAMEPAD_PLAYER1) && amplitude == 0) {
        // D-Pad as backup
        bool pressingRight = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
        bool pressingLeft = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_LEFT);
        bool pressingUp = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_UP);
        bool pressingDown = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_DOWN);
        amplitude = computeAmplitude(pressingLeft, pressingRight, pressingUp, pressingDown);
    }

    if (amplitude == 0) {
        // Keyboard as last hope
        bool pressingRight = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
        bool pressingLeft = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
        bool pressingUp = IsKeyDown(KEY_UP) || IsKeyDown(KEY_W);
        bool pressingDown = IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S);
        amplitude = computeAmplitude(pressingLeft, pressingRight, pressingUp, pressingDown);

    }

    return amplitude;
}

float Scene::computeAngle(bool left, bool right, bool up, bool down) {
    // Diagonal
    if (up && right) {
        return M_PI / 4;
    }
    if (up && left) {
        return 3 * M_PI / 4;
    }
    if (down && right) {
        return 7 * M_PI / 4;
    }
    if (down && left) {
        return 5 * M_PI / 4;
    }

    // Straight
    if (up) {
        return M_PI / 2;
    }
    if (down) {
        return 3 * M_PI / 2;
    }
    if (right) {
        return 0;
    }
    if (left) {
        return M_PI;
    }

    return 0;
}

float Scene::computeAmplitude(bool left, bool right, bool up, bool down) {
    float xAccel = 0;
    float yAccel = 0;

    if (up) {
        xAccel -= GHOST_ACCEL;
    }
    if (down) {
        xAccel += GHOST_ACCEL;
    }

    if (right) {
        yAccel += GHOST_ACCEL;
    }
    if (left) {
        yAccel -= GHOST_ACCEL;
    }

    return std::sqrt(std::pow(xAccel, 2) + std::pow(yAccel, 2));
}

GhostAction Scene::getInputAction() {
    /**
     Get which action the user is pressing
     Only triggered when pressing the key for the first time, holding it doesn't work
     Key names use qwerty input, but adapt to other keyboards
     */
    if (IsKeyPressed(KEY_E)
        || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) {
        return GhostAction::interact;
    }

    if (IsKeyPressed(KEY_Q)
        || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_LEFT)) {
        return GhostAction::shush;
    }

    if (IsKeyPressed(KEY_SPACE)
        || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_TRIGGER_2)
        || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_TRIGGER_2)) {
        return GhostAction::dash;
    }

    if (IsKeyPressed(KEY_ENTER)
        || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_TRIGGER_1)
        || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) {
        return GhostAction::fusrodah;
    }

    return GhostAction::none;
}

void Scene::spawnTable(float x, float y)
{
	Table table(x, y);
	std::shared_ptr<Table> ptable(new Table(x, y));
	tables.push_back(std::make_shared<Table>(table));
	nodes.push_back(std::make_shared<Table>(table));
}

void Scene::spawnPerson(Table& table)
{
	// Spawn a person
	Vector2 nextPosition = table.getNextPosition();
	Person person(nextPosition.x, nextPosition.y);
	person.enter(); // Toggle visibility on

	persons.push_back(std::make_shared<Person>(person));
	nodes.push_back(std::make_shared<Person>(person));
}
