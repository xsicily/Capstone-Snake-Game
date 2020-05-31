#ifndef GAME_H
#define GAME_H

#include <random>
#include <SDL2/SDL.h> 
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  // Constructor
  Game(std::size_t grid_width, std::size_t grid_height);

  // Behaviour methods
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);

  // getters / setters        
  int GetScore() const { return score; };
  int GetSize() const { return snake.size; };

 private:
  Snake snake; // Make an instance of snake object
  SDL_Point food; // Define food as SDL_Point

  // Pick width and height at random
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0}; // Initialize score as 0

  void PlaceFood(); // Return food coordinates
  void Update(); // Update snake(grow and speed), food and score
};

#endif