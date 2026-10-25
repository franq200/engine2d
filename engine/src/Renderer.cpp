#include <engine/Renderer.h>
#include <SDL3/SDL.h>

Renderer::Renderer(SDL_Window* window)
{
	renderer_ = SDL_CreateRenderer(window, nullptr);
	SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_BLEND);
}

Renderer::~Renderer()
{
	if (renderer_)
	{
		SDL_DestroyRenderer(renderer_);
	}
}

void Renderer::FillRect(Rect rect, Color color)
{
	if (!renderer_)
	{
		return;
	}
	SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
	SDL_FRect sdlRect = { rect.x, rect.y, rect.w, rect.h };
	SDL_RenderFillRect(renderer_, &sdlRect);
}

void Renderer::Clear(Color color)
{
	if (!renderer_)
	{
		return;
	}
	SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
	SDL_RenderClear(renderer_);
}

void Renderer::Present()
{
	if (!renderer_)
	{
		return;
	}
	SDL_RenderPresent(renderer_);
}