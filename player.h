#include"SDL/SDL.h"
#include "character.h"
#pragma once

class player:public character{
public:
  player();
  void handle_input(SDL_Event&);

private:
  /* data */
};

