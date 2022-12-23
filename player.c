#include "player.h"
#include "asset.h"
#include "main.h"

#include <stdlib.h>

// Create a player
Player* create_player() {
  Player* player = malloc(sizeof(Player));
  player->x = 0;
  player->y = 0;
  player->dx = 0;
  player->dy = 0;
  player->health = 3;
  player->alive = 1;
  player->jump_cooldown = 0;
  return player;
}

// Check if player is colliding with a solid block
int check_collision(int player_x, int player_y, int block_x, int block_y) {
  return player_x + PLAYER_WIDTH > block_x && player_x < block_x + BLOCK_WIDTH &&
         player_y + PLAYER_HEIGHT > block_y && player_y < block_y + BLOCK_HEIGHT;
}

// Update player state
// void update_player(Player* player, Block* blocks, int num_blocks) {
void update_player(Player* player) {
  // Update player position
  int new_x = player->x + player->dx;
  int new_y = player->y + player->dy;

  // Check for collisions with solid blocks
  // for (int i = 0; i < num_blocks; i++) {
  //   Block* block = &blocks[i];
  //   if (block->type == BLOCK_SOLID) {
  //     if (check_collision(new_x, new_y, block->x, block->y)) {
  //       // Adjust player position to prevent collision
  //       if (player->dx > 0) {
  //         new_x = block->x - PLAYER_WIDTH;
  //       } else if (player->dx < 0) {
  //         new_x = block->x + BLOCK_WIDTH;
  //       }
  //       if (player->dy > 0) {
  //         new_y = block->y - PLAYER_HEIGHT;
  //       } else if (player->dy < 0) {
  //         new_y = block->y + BLOCK_HEIGHT;
  //       }
  //     }
  //   }
  // }

  // Update player position with adjusted values
  player->x = new_x;
  player->y = new_y;

  // Update player velocity based on input
  // if (key_down(UP_KEY)) {
  //   jump(player);
  // }
  // if (key_down(LEFT_KEY)) {
  //   player->dx = -PLAYER_SPEED;
  // } else if (key_down(RIGHT_KEY)) {
  //   player->dx = PLAYER_SPEED;
  // } else {
  //   player->dx = 0;
  // }

  // // Update player jump cooldown
  // if (player->jump_cooldown > 0) {
  //   player->jump_cooldown--;
  // }

  // Update player gravity
  player->dy += PLAYER_GRAVITY;

  // // Attack
  // if (key_down(ATTACK_KEY)) {
  //   attack(player, enemies, num_enemies);
  // }
}

// Render player
void render_player(Player* player) {
  SDL_Rect rect = { player->x, player->y, PLAYER_WIDTH, PLAYER_HEIGHT };
  SDL_BlitSurface(player_sprite, NULL, SDL_GetWindowSurface(game_window), &rect);
}

// Jump
void jump(Player* player) {
  // Check if player is able to jump
  if (player->jump_cooldown == 0) {
    player->dy = -PLAYER_JUMP_SPEED;
    // Mix_PlayChannel(-1, game_sounds[SOUND_JUMP], 0);

    // Set jump cooldown
    player->jump_cooldown = PLAYER_JUMP_COOLDOWN;
  }
}

// Attack
// void attack(Player* player, Enemy* enemies, int num_enemies) {
//   // Iterate through enemies and check if player's attack hits
//   for (int i = 0; i < num_enemies; i++) {
//     Enemy* enemy = &enemies[i];
//     if (enemy->alive) {
//       if (abs(player->x - enemy->x) <= ENEMY_WIDTH && abs(player->y - enemy->y) <= ENEMY_HEIGHT) {
//         // Reduce enemy health
//         enemy->health--;
//         if (enemy->health == 0) {
//           enemy->alive = 0;
//           Mix_PlayChannel(-1, game_sounds[SOUND_DEATH], 0);
//         }
//       }
//     }
//   }
// }
