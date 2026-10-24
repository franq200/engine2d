#pragma once
#include <cstdint>

struct SDL_Renderer;
struct SDL_Window;

struct Color
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

class Renderer
{
public:
	Renderer(SDL_Window* window);
	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;
	~Renderer();

	void Clear(Color color);
	void Present();
private:
	SDL_Renderer* renderer_ = nullptr;
};