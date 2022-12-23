#include "main.h"
#include "game.h"
#include "player.h"
#include "enemy.h"
#include "asset.h"

#include <SDL2/SDL.h>

SDL_Window* game_window;

int main(int argc, char* argv[]) {

  // Initialize game window and rendering system
  if (init_game() != 0) {
    return 1;
  }

  // Load game assets
  if (load_assets() != 0) {
    return 1;
  }

  // Initialize game state
  GameState game_state;
  init_game_state(&game_state);

  // Main game loop
  while (game_state.running) {
    // Update game state
    update_game_state(&game_state);

    // Render game state
    render_game_state(&game_state);
  }

  // Clean up game assets
  unload_assets();

  // Clean up game window and rendering system
  cleanup_game();

  return 0;
}

int key_down(int key) {
  const Uint8* state = SDL_GetKeyboardState(NULL);
  return state[key];
}

int init_game() {
  // Initialize SDL and create game window
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  // Create game window
  game_window = SDL_CreateWindow(
    "Pixel Particle",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN
  );
  if (game_window == NULL) {
    fprintf(stderr, "Error creating game window: %s\n", SDL_GetError());
    return 1;
  }

  // Initialize other game subsystems here

  return 0;
}

void cleanup_game() {
  // Clean up game window and other game subsystems
  SDL_DestroyWindow(game_window);
  SDL_Quit();
}