#include <engine/Application.h>
#include <iostream>

class GameTest : public Application
{
private:
	int fixedCount_ = 0;
	int frameCount_ = 0;
	double timer_ = 0.0;

	void OnFixedUpdate(double dt) override
	{
		fixedCount_++;
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
};

int main()
{
    GameTest game;
    game.Run();
    return 0;
}