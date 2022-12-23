#ifndef ASSET_H
#define ASSET_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define NUM_ENEMY_SPRITES 3
#define NUM_GAME_SOUNDS 3

enum {
  SOUND_JUMP,
  SOUND_HURT,
  SOUND_DEATH
};

extern SDL_Surface* player_sprite;
extern SDL_Surface* enemy_sprites[NUM_ENEMY_SPRITES];
extern Mix_Music* game_music;
extern Mix_Chunk* game_sounds[NUM_GAME_SOUNDS];

int load_assets();
void unload_assets();

#endif
