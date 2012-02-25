#include "SDL/SDL.h"

#pragma once

class environment{
  private:
    SDL_Surface* background;

  public:
    environment();
    ~environment(); 
    SDL_Rect camera;
		void load_background(char [], int); //primeste de la level numele backgroundului si width-ul lui si il incarca in RAM
    void render_background(SDL_Surface *screen); //rendereaza backgroundul pe screen
    void set_ground(char []); //citeste din fisierul cu path-ul dat dreptunghiurile in care poate sta caracterul
};
