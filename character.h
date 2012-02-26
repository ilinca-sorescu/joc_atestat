#include "SDL/SDL.h"
#include "animation.h"
#include <vector>

using namespace std;

#pragma once

struct offset{
  int x, y, vx, vy;
};

class character{
  protected:
    vector<animation*> A;
    int current_animation;
    offset o;
    void move();
  public:
    character();
    ~character();
    void add_animation(animation*);
    offset get_offset();
    void set_offset(offset);
    void set_current_animation(int);
    void render(SDL_Surface*, SDL_Rect*);
};
