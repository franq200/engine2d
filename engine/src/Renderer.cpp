#include <engine/Renderer.h>
#include <SDL3/SDL.h>

Renderer::Renderer(SDL_Window* window)
{
	renderer_ = SDL_CreateRenderer(window, nullptr);
}

Renderer::~Renderer()
{
	if (renderer_)
	{
		SDL_DestroyRenderer(renderer_);
	}
}

void Renderer::Clear(Color color)
{
	if (renderer_)
	{
		SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
		SDL_RenderClear(renderer_);
	}
}

void Renderer::Present()
{
	if (renderer_)
	{
		SDL_RenderPresent(renderer_);
	}
}