#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_WIDTH 5
#define PLAYER_HEIGHT 5
#define PLAYER_SPEED 5
#define PLAYER_JUMP_COOLDOWN 10
#define PLAYER_JUMP_SPEED 10
#define PLAYER_GRAVITY 3

#define BLOCK_HEIGHT 5
#define BLOCK_WIDTH 5
#define BLOCK_SOLID 0

#include <SDL2/SDL.h>

typedef struct {
  int x;
  int y;
  int width;
  int height;
  int type;
  int health;
} Block;


typedef struct {
  int x;
  int y;
  int dx;
  int dy;
  int health;
  int alive;
  int attack_cooldown;
  int jump_cooldown;
} Player;

Player* create_player();
void update_player(Player* player);
void render_player(Player* player);

#endif
