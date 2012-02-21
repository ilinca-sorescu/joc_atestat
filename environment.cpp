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
  SDL_Surface* loadedImage = NULL;
  loadedImage = SDL_LoadBMP(filename);
  if(loadedImage == NULL)
    throw 1;
  this->background = SDL_DisplayFormat(loadedImage);
  SDL_FreeSurface(loadedImage);
}

void environment::render_background(SDL_Surface *screen){
  SDL_BlitSurface(this->background, &(this->camera), screen, NULL);
}

void environment::set_ground(char filename[]){
}
