#include "SDL/SDL.h"
#include "level.h"

const int FRAMES_PER_SECOND = 20;


//main prog -- regulating frame rate
//          -- init 


void init(){
  if(SDL_Init( SDL_INIT_EVERYTHING ) == -1)
    throw 1;
  
  SDL_WM_SetCaption("Crili!", NULL);
}

void regulate_fps(){
  static int last_T = 0;
  int T = SDL_GetTicks();
  if((T - last_T) < 1000 / FRAMES_PER_SECOND)
    SDL_Delay(1000 / FRAMES_PER_SECOND - T + last_T);
  last_T = T;
}

int main(int argc, char* args[]){
  level L;
  L.init(1);

  try{
    
    init();

    while(L.quit() == false){
      L.handle_input();
      L.render_all();
      regulate_fps();   
    }
  }
  
  catch(int e){
  }

  SDL_Quit();
  return 0;
}

