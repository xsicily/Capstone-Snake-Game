#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <SDL2/SDL.h> 
#include "snake.h"
#include <memory>
#include "shared.h"

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
  /*
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  */
  struct sdl_deleter
  {
    void operator()(SDL_Window *p) const{
      SDL_DestroyWindow(p);
    }
    void operator()(SDL_Renderer *p) const{
      SDL_DestroyRenderer(p);
    }
  };
  std::unique_ptr<SDL_Window, sdl_deleter> sdl_window;
  std::unique_ptr<SDL_Renderer, sdl_deleter> sdl_renderer;

 
  
  // Member variables
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif