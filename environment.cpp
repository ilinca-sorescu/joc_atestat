#include "SDL/SDL.h"
#include "environment.h"

environment::environment(){
  this->background = NULL;
  camera.x = camera.y = 0;
  camera.w = camera.h = 600;
}

environment::~environment(){
  SDL_FreeSurface(this->background);
}

void environment::load_background(char filename[], int width){
  this->BACKGROUND_WIDTH = width;
  
  SDL_Surface* loadedImage = NULL;
  loadedImage = SDL_LoadBMP(filename);
  if(loadedImage == NULL)
    throw 1;
  this->background = SDL_DisplayFormat(loadedImage);
  SDL_FreeSurface(loadedImage);
}

int environment::get_background_width(){
  return this->BACKGROUND_WIDTH;
}

void environment::render_background(SDL_Surface *screen){
  SDL_BlitSurface(this->background, &(this->camera), screen, NULL);
}

void environment::move(int x, int dx){
  this->camera.x = x + dx/2 - 300;

  if(this->camera.x < 0)
    this->camera.x = 0;

  if(this->camera.x + this->camera.w > this->BACKGROUND_WIDTH)
    this->camera.x = this->BACKGROUND_WIDTH - this->camera.w;
}

void environment::set_ground(char filename[]){
}
