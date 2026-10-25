#include <engine/Application.h>
#include <engine/Renderer.h>
#include <iostream>

class GameTest : public Application
{
private:
	int fixedCount_ = 0;
	int frameCount_ = 0;
	double timer_ = 0.0;
	Rect rect_ = { 100, 100, 200, 200 };

	void OnFixedUpdate(double dt) override
	{
		fixedCount_++;
		rect_.x += 10.0f * static_cast<float>(dt);
	}
	void OnUpdate(double dt) override
	{
		frameCount_++;
		timer_ += dt;
		if (timer_ >= 1.0)
		{
			std::cout << "fixed: " << fixedCount_ << "  fps: " << frameCount_ << '\n';
			frameCount_ = 0;
			fixedCount_ = 0;
			timer_ -= 1.0;
		}
	}
	void OnRender(Renderer& renderer) override
	{
		renderer.FillRect(rect_, { 255, 0, 0, 255 });
	}
};

int main()
{
    GameTest game;
    game.Run();
    return 0;
}