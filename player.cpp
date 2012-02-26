#include <cstdio>
#include "SDL/SDL.h"
#include "player.h"

player::player():character(){
  FILE* pFile;
  pFile = fopen("player/animation-info.txt", "r");
  if(pFile == NULL)
    throw 1;

  int n, i;
  char imagename[45];
  int no_of_frames, width, height;
  animation* a;
  fscanf(pFile, "%d", &n);
  for(i = 1; i <= n; ++i){
    fscanf(pFile, "%s%d%d%d", imagename, &no_of_frames, &width, &height);
    a = new animation(imagename, width, height, no_of_frames);
    this->add_animation(a);
  }

  if(n == 0) 
    throw 1;
  this->set_current_animation(0);
}

void player::move(environment& E){
  if(this->o.vx == 0)
    return;

  this->o.x += this->o.vx;

  if(this->o.x < 0 || this->o.x > E.get_background_width() - 50)
    this->o.x -= this->o.vx;

  int k;
  if(this->o.vx > 0)
    k = 0;
  else
    k = 1;
  if(k == this->current_animation)
    this->A[this->current_animation]->increment_frame();
  else{
    this->current_animation = k;
    this->A[this->current_animation]->set_frame(0);
  }

  E.move(this->o.x, this->A[current_animation]->get_width());
}


void player::handle_input(SDL_Event& event){
  if(event.type == SDL_KEYDOWN){
    switch(event.key.keysym.sym){
      case SDLK_RIGHT: this->o.vx += this->A[current_animation]->get_width()/4; break;
      case SDLK_LEFT:  this->o.vx -= this->A[current_animation]->get_width()/4; break;
    }
  }
    else if(event.type == SDL_KEYUP){
      switch(event.key.keysym.sym){
        case SDLK_RIGHT: this->o.vx -= this->A[current_animation]->get_width()/4; break;
        case SDLK_LEFT:  this->o.vx += this->A[current_animation]->get_width()/4; break;
      }
    }
}
