#include "SDL/SDL.h"

#include <cstring>
#include <cstdio>
#include "level.h"

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;


level::level(){
  this->Q = false;

  this->number_of_levels = 1;

  this->screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
 
  if(this->screen == NULL)
    throw 1;

  int i;
  FILE* pFile;
  pFile = fopen("background_names.txt", "r");
  if(pFile == NULL)
    throw 1;
  for(i = 1; i <= number_of_levels; ++i)
    fscanf(pFile, "%s%d", background_name[i], &background_width[i]);
  fclose(pFile);
}

void level::init(int x){
  this->level_no = x;
  this->level_width = this->background_width[this->level_no];
  E.load_background(this->background_name[this->level_no], this->background_width[this->level_no]);
}

bool level::quit(){
  return this->Q;
}

void level::render_all(){
  E.render_background(screen);
//  P.render(screen, &E.camera);

  if(SDL_Flip(screen) == -1)
    throw 1;
}

void level::handle_input(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_QUIT){
      this->Q = true;
      return;
    }
    P.handle_input(event);
  }
}


