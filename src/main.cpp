#include "main.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

bool App::init()  // returns true on success
{
	std::cout << "Initializing BayLeaf Engine v0.0.1..." << '\n';

	int result = SDL_Init(SDL_INIT_VIDEO);
	if (result != 0)
	{
		std::cout << "FAIL: SDL_Init() error: " << SDL_GetError() << std::endl;
		return false;
	}

	window_ = SDL_CreateWindow("BayLeaf Engine v0.0.1", 1, 32, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (!window_)
	{
		std::cout << "FAIL: SDL_CreateWindow() error: " << SDL_GetError() << std::endl;
		return false;
	}

	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);  // NOTE: enable vsync here
	if (!renderer_)
	{
		std::cout << "FAIL: SDL_CreateRenderer() error: " << SDL_GetError() << std::endl;
		return false;
	}

	// IMG_Init()

	// TTF_Init()

	return true;
}

int main(int argc, char* argv[])
{
	App app;
	return app.init();
	// TODO: app.run(); app.quit();
}