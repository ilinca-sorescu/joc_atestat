#include "SDL/SDL.h"
#include "animation.h"

void animation::animation(){
  this->frame = 0;
  this->no_of_frames = 0;
  this->image = NULL;
}

void animation::animation(int x){
  this->frame = 0;
  this->no_of_frames = x;
  this->clips.resize(x);
  this->image = NULL;
}

void animation::~animation(){
  SDL_FreeSurface(this->image);
}

void animation::set_no_of_frames(int x){
  this->no_of_frames = x;
  this->clips.resize(x);
}

void animation::set_frame(int x){
  this->frame = x;
}

void animation::load_animation(char imagename[], int width, int height){
  //1. load image
  SDL_Surface* loadedImage = NULL;
  loadedImage = SDL_LoadBMP(filename);
  if(loadedImage == NULL)
    throw 1;
  this->image = SDL_DisplayFormat(loadedImage);
  SDL_FreeSurface(loadedImage);
  if(this->image == NULL)
   throw 1;
  SDL_SetColorKey(this->image, SDL_SRCCOLORKEY, SDL_MapRGB(this->image->format, 0, 0xFF, 0xFF)); //!!!!!!!!!!!!!!
  //-----------------------------------

  //2. get clips
  int i;
  for(i = 0; i != this->no_of_frames; ++i){
    this->clip[i].x = i * width;
    this->clip[i].y = 0;
    this->clip[i].w = width;
    this->clip[i].h = height;
  }
  //-----------------------------------
}
