#include <engine/Application.h>
#include <chrono>
#include <SDL3/SDL.h>
#include <engine/Renderer.h>

using Clock = std::chrono::steady_clock;

Application::Application()
{
	SDL_Init(SDL_INIT_VIDEO);
	window_ = SDL_CreateWindow("My Application", 1000, 1000, SDL_WINDOW_RESIZABLE);
	renderer_ = std::make_unique<Renderer>(window_);
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
	const double fixedStep = 1.0 / static_cast<double>(updatesPerSecond_);
	const double maxFrameTime = 0.25;
	double accumulator = 0.0;
	Clock::time_point previousTime = Clock::now();

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
		if (!running)
		{
			break;
		}

		Clock::time_point currentTime = Clock::now();
		double dt = std::chrono::duration<double>(currentTime - previousTime).count();
		if (dt > maxFrameTime)
		{
			dt = maxFrameTime;
		}
		accumulator += dt;
		previousTime = currentTime;

		while (accumulator >= fixedStep)
		{
			OnFixedUpdate(fixedStep);
			accumulator -= fixedStep;
		}

		OnUpdate(dt);
		renderer_->Clear({ 67, 50, 255, 255 });
		OnRender(*renderer_);
		renderer_->Present();
	}
}