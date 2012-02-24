#include "SDL/SDL.h"
#include<vector>

using namespace std;

#pragma once

class animation{
  private:
    SDL_Surface* image;
    vector<SDL_Rect> clips;
    int frame;
    int no_of_frames;
  public:
    animation();
    animation(int);
    ~animation();
    void set_no_of_frames(int);
    void set_frame(int);
    void load_animation(char [], int, int);    
};
