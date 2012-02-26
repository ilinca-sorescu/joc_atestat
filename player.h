#include"SDL/SDL.h"
#include "character.h"
#include "environment.h"
#pragma once

class player:public character{
public:
  player();
  void handle_input(SDL_Event&);
  void move(environment&);

private:
  /* data */
};

