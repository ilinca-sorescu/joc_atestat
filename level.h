#include "SDL/SDL.h"
#include "environment.h"

#pragma once

class level{
  public:
    level();
    void init(int);
    void render_all();
    void handle_input();
    bool quit();
  private:
    SDL_Surface *screen;
    int Q;
    int level_no;
    int level_width;
    int number_of_levels;
    int background_width[10];
    char background_name[10][30];
    environment E;
};
