#include "SDL/SDL.h"
#include<vector>

using namespace std;

character::character(){
  this->current_animation = 1;
  this->A[x]->frame = 0;
  this->o.x = 0;
  this->o.y = ;//!!!!!!!!!!!!!!!!!!
  this->o.vx = 0;
  this->o.vy = 0;
}

character::~character(){
  int i;
  for(i = 0; i != this->A.size(); ++i)
    delete this->A[i];
}

void character::add_animation(animation* a){
  A.push_back(a);
}

offset character::get_offset(){
  return this->o;
}

void character::set_offset(offset k){
  this->o = k;
}

void character::set_current_animation(int x){
  this->current_animation = x;
  this->A[x]->frame = 0;
}

void character::render(SDL_Surface* screen, SDL_Rect* camera){
  ++this->A[current_animation]->frame;
  if(this->A[current_animation]->frame == this->A[current_animation]->no_of_frames)
     this->A[current_animation]->frame = 0;
  //!!!!!!!!!!!!!!!!!!!!
}
