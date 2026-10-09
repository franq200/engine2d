#include <engine/Application.h>
#include <SDL3/SDL.h>

Application::Application()
{
	SDL_Init(SDL_INIT_VIDEO);
	window_ = SDL_CreateWindow("My Application", 1000, 1000, SDL_WINDOW_RESIZABLE);
}

Application::~Application()
{
	if (window_)
	{
		SDL_DestroyWindow(window_);
	}
	SDL_Quit();
}

void Application::Run()
{
	bool running = true;
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
			{
				running = false;
			}
		}
	}
}