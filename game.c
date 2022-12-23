#include "game.h"
#include "player.h"
#include "enemy.h"

void init_game_state(GameState* game_state) {
  game_state->running = 1;
  game_state->player = create_player();
  game_state->enemies = create_enemies();
  // Initialize other game state variables here
}

void update_game_state(GameState* game_state) {
  // update_player(game_state->player);
  update_enemies(game_state->enemies);
  // Update other game state variables here
}

void render_game_state(GameState* game_state) {
  render_game_world(game_state);
  render_player(game_state->player);
  render_enemies(game_state->enemies);
  // Render other game elements here
}

// Render game world
void render_game_world(GameState* game_state) {
  // Render game world elements here
}