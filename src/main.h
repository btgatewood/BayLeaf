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

class Game
{
public:
	void update() {}
	void render() {}

	bool quit() { return quit_; }

private:
	bool quit_{ false };
};

class App
{
public:
	bool init();
	void mainloop();
	void shutdown();

private:
	SDL_Window* window_{ nullptr };
	SDL_Renderer* renderer_{ nullptr };
	Game game_{};
	bool quit_{ false };
};