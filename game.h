#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "enemy.h"

typedef struct {
  int running;
  Player* player;
  Enemy* enemies;
  // Other game state variables
} GameState;

void init_game_state(GameState* game_state);
void update_game_state(GameState* game_state);
void render_game_state(GameState* game_state);
void render_game_world(GameState* game_state);

#endif
