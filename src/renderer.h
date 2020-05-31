#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <SDL2/SDL.h> 
#include "snake.h"
#include <memory>

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
  
  /*
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  */
 
  // customize a SDL deleter
  struct sdl_deleter
  {
    void operator()(SDL_Window *p) const{
      SDL_DestroyWindow(p);
    }
    void operator()(SDL_Renderer *p) const{
      SDL_DestroyRenderer(p);
    }
  
    void operator()(SDL_Surface *p) const{
      SDL_FreeSurface(p);
    }
    void operator()(SDL_Texture *p) const{
      SDL_DestroyTexture(p);
    }
    
  };

  //make sdl_window an exclusive resource to <SDL_Window, sdl_deleter> using smart pointer
  //make sdl_renderer an exclusive resource to <SDL_Renderer, sdl_deleter> using smart pointer
  std::unique_ptr<SDL_Window, sdl_deleter> sdl_window;
  std::unique_ptr<SDL_Renderer, sdl_deleter> sdl_renderer;

  std::unique_ptr<SDL_Surface, sdl_deleter> surface;
  std::unique_ptr<SDL_Texture, sdl_deleter> texture;
  

  // Member variables
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif