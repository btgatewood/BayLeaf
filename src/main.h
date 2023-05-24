#pragma once

#include <iostream>  // using std::cout
#include <string>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

class App
{
public:
	bool init();
private:
	SDL_Window* window_{ nullptr };
	SDL_Renderer* renderer_{ nullptr };
};