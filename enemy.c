#include "enemy.h"
#include "player.h"
#include "asset.h"
#include "game.h"
#include "main.h"

#include <stdlib.h>

// Create array of enemies
Enemy* create_enemies() {
  Enemy* enemies = malloc(sizeof(Enemy) * NUM_ENEMIES);
  // Initialize enemy variables here
  return enemies;
}

// Initialize an enemy
void init_enemy(Enemy* enemy, int x, int y) {
  enemy->x = x;
  enemy->y = y;
  enemy->dx = 0;
  enemy->dy = 0;
  enemy->health = 3;
  enemy->alive = 1;
  enemy->attack_cooldown = 0;
  enemy->sprite_index = rand() % NUM_ENEMY_SPRITES;
}

// Update enemy state
void update_enemies(Enemy* enemies) {
  for (int i = 0; i < NUM_ENEMIES; i++) {
    update_enemy(&enemies[i]);
  }
}
// Render enemies
void render_enemies(Enemy* enemies) {
  for (int i = 0; i < NUM_ENEMIES; i++) {
    render_enemy(&enemies[i]);
  }
}

// Update enemy state
void update_enemy(Enemy* enemy) {
  // Update enemy position
  enemy->x += enemy->dx;
  enemy->y += enemy->dy;

  // Update enemy attack cooldown
  if (enemy->attack_cooldown > 0) {
    enemy->attack_cooldown--;
  }
}

// Render enemy
void render_enemy(Enemy* enemy) {
  SDL_Rect rect = { enemy->x, enemy->y, ENEMY_WIDTH, ENEMY_HEIGHT };
  SDL_BlitSurface(enemy_sprites[enemy->sprite_index], NULL, SDL_GetWindowSurface(game_window), &rect);
}

// Attack player
// void attack_player(Enemy* enemy, Player* player) {
//   // Check if enemy is able to attack
//   if (enemy->attack_cooldown == 0) {
//     // Reduce player health
//     player->health--;
//     Mix_PlayChannel(-1, game_sounds[SOUND_HURT], 0);

//     // Set attack cooldown
//     enemy->attack_cooldown = ENEMY_ATTACK_COOLDOWN;
//   }
// }
