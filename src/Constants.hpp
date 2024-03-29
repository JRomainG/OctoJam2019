#pragma once

#define GHOST_ACCEL 8000
#define GHOST_DASH_ACCEL (10 * GHOST_ACCEL)
#define GHOST_FRICTION 0.7
#define GHOST_MAX_SPEED 45000
#define GHOST_DASH_COOLDOWN 1.0
#define GHOST_MIN_SPEED_FOR_DASH 10

#define GHOST_FLOAT_FREQUENCY 4
#define GHOST_FLOAT_AMPLITUDE 5

#define GHOST_TRANSPARENCY 200 // Between 0 and 255

#define GHOST_ACTION_RANGE 100

#define EVENT_ACTION_RANGE 200

#define CAMERA_SLOW_RATIO 0.25
#define CAMERA_CATCHUP_RATIO 3

#define MAP_BORDER_SIZE 16

#define TILE_SIZE 16
#define SPRITES_SCALE 4

#define BACKGROUND_COLOR Color{ 106, 101, 118, 255 }

#define GHOST_FLOAT_FREQUENCY 4
#define GHOST_FLOAT_AMPLITUDE 5

#define PERSON_FADE_DURATION 0.5

#define SCENE_TRANSITION_DURATION 1

#define MIN_TIME_BEFORE_LOSS 1
#define MIN_TIME_BEFORE_BECOME_EXCITED 3
#define RANDOMLY_BECOME_EXCITED_PROBABILITY 0.01
#define BECOME_SCARED_AFTER_INTERACTION_PROBABILITY 0.2
#define BECOME_CALM_PROBABILITY 0.05
#define LEAVE_AFTER_INTERACTION_PROBABILITY 0.25

// Expected size, we'll zoom in/out to get to the same view
#define GAME_WIDTH 1280
#define GAME_HEIGHT 720
