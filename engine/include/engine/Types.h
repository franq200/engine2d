#pragma once
#include <cstdint>

struct Color
{
	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;
	uint8_t a = 0;
};

struct Rect
{
	float x = 0.0f;
	float y = 0.0f;
	float w = 0.0f;
	float h = 0.0f;
};