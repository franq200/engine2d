#pragma once

struct SDL_Window;

class Application
{
public:
    Application();
    virtual ~Application();
    void Run();
private:
    SDL_Window* window_ = nullptr;
	int updatesPerSecond_ = 60;
protected:
    virtual void OnFixedUpdate(double dt) {};
	virtual void OnUpdate(double dt) {};
	virtual void OnRender() {};
};