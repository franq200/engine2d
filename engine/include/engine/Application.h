#pragma once

struct SDL_Window;

class Application
{
public:
    Application();
    ~Application();
    void Run();
private:
    SDL_Window* window_ = nullptr;
};