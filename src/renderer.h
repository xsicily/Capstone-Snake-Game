#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"

class Renderer {
 public:
  //Constructor
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  //Destructor
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food);// Render snake and food
  void UpdateWindowTitle(int score, int fps);// Update window title: snake score and FPS

 private:
  //
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  
  // Member variables
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif