#pragma once
#include "SimpleWindow.h"

struct RECT
{
	float X;
	float Y;
	float Width;
	float Height;
};

struct BOARD
{
	float X;
	float Y;
	float RectWidth;
	float RectHeight;
	int32_t SizeX;
	int32_t SizeY;
};

class SimpleUI
{
private:
	int32_t m_Hot;
	int32_t m_Active;

public:
	SimpleUI();

	bool Button(int32_t id, RECT shape, Color color);
	bool Panel(int32_t id, BOARD shape, std::vector<bool>& state);
	void Text(int32_t id, float X, float Y, std::string text, int32_t fontSize, Color color, Font* font) const;

private:
	static bool TestPointInRect(RECT shape);
};
