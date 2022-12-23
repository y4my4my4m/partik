#ifndef MAIN_H
#define MAIN_H

#define UP_KEY SDLK_UP
#define DOWN_KEY SDLK_DOWN
#define LEFT_KEY SDLK_LEFT
#define RIGHT_KEY SDLK_RIGHT
#define ATTACK_KEY SDLK_SPACE

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include <SDL2/SDL.h>

extern SDL_Window* game_window;

int init_game();
void cleanup_game();
int key_down(int key);

#endif