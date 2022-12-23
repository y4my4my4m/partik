#ifndef ENEMY_H
#define ENEMY_H

#define ENEMY_WIDTH 5
#define ENEMY_HEIGHT 5
#define ENEMY_SPEED 1
#define ENEMY_ATTACK_COOLDOWN 60

#define NUM_ENEMIES 3

#include <SDL2/SDL.h>
#include "player.h"

typedef struct {
  int x;
  int y;
  int dx;
  int dy;
  int health;
  int alive;
  int attack_cooldown;
  int sprite_index;
} Enemy;

Enemy* create_enemies();
void init_enemy(Enemy* enemy, int x, int y);
void update_enemies(Enemy* enemies);
void update_enemy(Enemy* enemy);
void render_enemies(Enemy* enemies);
void render_enemy(Enemy* enemy);
// void attack_player(Enemy* enemy, Player* player);

#endif
