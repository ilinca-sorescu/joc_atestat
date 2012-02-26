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


void player::handle_input(SDL_Event& event){
}
