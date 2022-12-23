#include "asset.h"
#include "player.h"
#include "enemy.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


// Define sprites
SDL_Surface* player_sprite;
SDL_Surface* enemy_sprites[];
Mix_Music* game_music;
Mix_Chunk* game_sounds[];

// Load game assets
int load_assets() {
  // Load player sprite
  player_sprite = SDL_LoadBMP("player.bmp");
  if (player_sprite == NULL) {
    fprintf(stderr, "Error loading player sprite: %s\n", SDL_GetError());
    return 1;
  }

  // Load enemy sprites
  enemy_sprites[0] = SDL_LoadBMP("enemy1.bmp");
  enemy_sprites[1] = SDL_LoadBMP("enemy2.bmp");
  enemy_sprites[2] = SDL_LoadBMP("enemy3.bmp");
  for (int i = 0; i < NUM_ENEMY_SPRITES; i++) {
    if (enemy_sprites[i] == NULL) {
      fprintf(stderr, "Error loading enemy sprite %d: %s\n", i, SDL_GetError());
      return 1;
    }
  }

  // // Load game music
  // game_music = Mix_LoadMUS("game_music.mp3");
  // if (game_music == NULL) {
  //   fprintf(stderr, "Error loading game music: %s\n", Mix_GetError());
  //   return 1;
  // }

  // Load game sounds
  // game_sounds[SOUND_JUMP] = Mix_LoadWAV("jump.wav");
  // game_sounds[SOUND_HURT] = Mix_LoadWAV("hurt.wav");
  // game_sounds[SOUND_DEATH] = Mix_LoadWAV("death.wav");
  // for (int i = 0; i < NUM_GAME_SOUNDS; i++) {
  //   if (game_sounds[i] == NULL) {
  //     fprintf(stderr, "Error loading game sound %d: %s\n", i, Mix_GetError());
  //     return 1;
  //   }
  // }

  return 0;
}

// Unload game assets
void unload_assets() {
  // Free player sprite
  SDL_FreeSurface(player_sprite);

  // Free enemy sprites
  for (int i = 0; i < NUM_ENEMY_SPRITES; i++) {
    SDL_FreeSurface(enemy_sprites[i]);
  }

  // Free game music
  // Mix_FreeMusic(game_music);

  // Free game sounds
  // for (int i = 0; i < NUM_GAME_SOUNDS; i++) {
  //   Mix_FreeChunk(game_sounds[i]);
  // }
}