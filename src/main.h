#pragma once

#include <iostream>  // using std::cout
#include <string>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

class App
{
public:
	bool init();
	void quit();

	bool run();

private:
	SDL_Window* window_{ nullptr };
	SDL_Renderer* renderer_{ nullptr };
};