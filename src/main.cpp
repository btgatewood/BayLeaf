#include "main.h"

bool App::init()  // returns true on success
{
	std::cout << "Initializing BayLeaf Engine v0.0.1..." << '\n';

	int result = SDL_Init(SDL_INIT_VIDEO);
	if (result != 0)
	{
		std::cout << "SDL_Init() error: " << SDL_GetError() << '\n';
		return false;
	}

	window_ = SDL_CreateWindow("BayLeaf Engine v0.0.1", 1, 32, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (!window_)
	{
		std::cout << "SDL_CreateWindow() error: " << SDL_GetError() << '\n';
		return false;
	}

	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);  // NOTE: enable vsync here
	if (!renderer_)
	{
		std::cout << "SDL_CreateRenderer() error: " << SDL_GetError() << '\n';
		return false;
	}

	int flags{ IMG_INIT_PNG };
	result = IMG_Init(flags);  // init sdl img lib, enable png support
	if (flags != result)
	{
		std::cout << "IMG_Init(IMG_INIT_PNG) error: " << IMG_GetError() << '\n';
		return false;
	}

	if (TTF_Init() == -1)  // init sdl ttf lib
	{
		std::cout << "TTF_Init() error: " << TTF_GetError() << '\n';
		return false;
	}

	std::cout << "BayLeaf Engine initialized!\n";
	return true;
}

void App::quit()
{
	std::cout << "BayLeaf Engine shutting down...\n";

	TTF_Quit();
	IMG_Quit();

	if (renderer_)
	{
		SDL_DestroyRenderer(renderer_);  // destroys associated textures
		renderer_ = nullptr;
	}

	if (window_)
	{
		SDL_DestroyWindow(window_);
		window_ = nullptr;
	}

	SDL_Quit();

	std::cout << "BayLeaf Engine shutdown!  Goodbye!\n";
}

bool App::run()  // returns false if user quits
{
	// process events
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			return false;
		}
	}

	// update

	// render

	return true;
}

int main(int argc, char* argv[])
{
	App app;
	app.init();
	while (app.run()) {}
	app.quit();
	return 0;
}