#pragma once
#include <engine/Types.h>

struct SDL_Renderer;
struct SDL_Window;

class Renderer
{
public:
	Renderer(SDL_Window* window);
	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;
	~Renderer();

	void FillRect(Rect rect, Color color);
	void Clear(Color color);
	void Present();
private:
	SDL_Renderer* renderer_ = nullptr;
};