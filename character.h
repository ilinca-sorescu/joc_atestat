// by 80$$ ilinq
// designed by 80$$an0va Crystynyque
#include "SDL/SDL.h"
#include "animation.h"
#include <vector>

using namespace std;

#pragma once

struct offset{
  int x, y, vx, vy;
};

class character{
  private:
    vector<animation*> A;
    offset o;
  public:
    character();
    ~character();
    void add_animation(animation);
    offset get_offset();
    void set_offset(offset);
    void set_current_animation(int);
    void display(SDL_Surface*);
};