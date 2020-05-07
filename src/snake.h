#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  // Define snake's moving direction
  enum class Direction { kUp, kDown, kLeft, kRight };

  // Constructor
  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  
  void Update(); // Update snake's head and body

  // getter and setter
  void GrowBody(){ growing = true; };

  bool SnakeCell(int x, int y); // flag indicating whether the cell is occupied by snake or not


  Direction direction = Direction::kUp; // Initialize snake's moving direction as kUp

  float speed{0.1f}; // Initialize moving speed as 0.1f
  int size{1}; // Initialize snake size as 1
  bool alive{true}; // flag indicating whether snake is alive or not
  float head_x; 
  float head_y;

  std::vector<SDL_Point> body;

 private:
  void UpdateHead(); // Update snake's head 
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell); //  Update snake's status: growing, not growing or dead

  //private members
  bool growing{false}; //flag indicating snake which is not growing
  int grid_width;
  int grid_height;
};

#endif