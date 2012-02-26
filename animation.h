#include "SDL/SDL.h"
#include<vector>

using namespace std;

#pragma once

class animation{
  private:
    vector<SDL_Rect> clips;
    int frame;
    int no_of_frames;
    int width, height;
  public:
    animation();
    animation(int);
    animation(char [], int, int, int);
    ~animation();
    SDL_Surface* image;
    int get_width();
    int get_frame();
    void set_frame(int);
    void load_animation(char [], int, int, int);
    SDL_Rect operator [] (int);
    SDL_Rect & clip();
    void increment_frame();
};
