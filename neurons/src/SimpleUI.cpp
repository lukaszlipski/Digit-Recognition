#include "SimpleUI.h"

SimpleUI::SimpleUI()
{
	m_Active = -1;
	m_Hot = -1;
}

bool SimpleUI::Button(int32_t id, RECT shape, Color color)
{
	Sprite sprite(Texture(), IntRect(0, 0, static_cast<int32_t>(shape.Width), static_cast<int32_t>(shape.Height)));
	sprite.setPosition(Vector2f(shape.X, shape.Y));
	sprite.setColor(color);
	SimpleWindow::GetInstance().Draw(&sprite);

	if (m_Active == id && TestPointInRect(shape) && SimpleWindow::GetInstance().GetMouseButtonState(Mouse::Left))
	{
		m_Active = -1;
		m_Hot = id;
		return true;
	}
	else if (TestPointInRect(shape) && !SimpleWindow::GetInstance().GetMouseButtonState(Mouse::Left))
	{
		m_Hot = id;
		m_Active = id;
	}


	return false;
}

bool SimpleUI::Panel(int32_t id, BOARD shape, std::vector<bool>& state)
{
	const float SPACE = 3;
	Sprite sprite(Texture(), IntRect(0, 0, shape.RectWidth, shape.RectHeight));

	Sprite box(Texture(), IntRect(0, 0, static_cast<int32_t>((shape.RectWidth + SPACE) * shape.SizeX + SPACE), static_cast<int32_t>((shape.RectHeight + SPACE) * shape.SizeY + SPACE)));
	box.setPosition(Vector2f(shape.X, shape.Y));
	box.setColor(Color(33, 33, 33));
	SimpleWindow::GetInstance().Draw(&box);

	for (int32_t y = 0; y < shape.SizeY; y++)
	{
		for (int32_t x = 0; x < shape.SizeX; x++)
		{
			float posX = SPACE + shape.X + x * (shape.RectWidth + SPACE);
			float posY = SPACE + shape.Y + y * (shape.RectHeight + SPACE);

			if (TestPointInRect(RECT{posX,posY,shape.RectWidth,shape.RectHeight}) && SimpleWindow::GetInstance().GetMouseButtonState(Mouse::Left)) { state[y * shape.SizeX + x] = true; }

			sprite.setPosition(Vector2f(posX, posY));
			if (state[y * shape.SizeX + x])
				sprite.setColor(Color(3, 155, 229));
			else
				sprite.setColor(Color(176, 190, 197));
			SimpleWindow::GetInstance().Draw(&sprite);
		}
	}

	RECT test{shape.X,shape.Y, (shape.RectWidth + SPACE) * shape.SizeX + SPACE, (shape.RectHeight + SPACE) * shape.SizeY + SPACE};
	if (TestPointInRect(test) && SimpleWindow::GetInstance().GetMouseButtonState(Mouse::Left))
	{
		m_Hot = id;
		m_Active = id;
	}
	else if (m_Active == id && TestPointInRect(test) && !SimpleWindow::GetInstance().GetMouseButtonState(Mouse::Left))
	{
		m_Hot = id;
		m_Active = -1;
		return true;
	}

	return false;
}

void SimpleUI::Text(int32_t id, float X, float Y, std::string text, int32_t fontSize, Color color, Font* font) const
{
	sf::Text output;
	output.setFont(*font);
	output.setString(text);
	output.setCharacterSize(fontSize);
	output.setFillColor(color);
	output.setPosition(Vector2f(X, Y));
	SimpleWindow::GetInstance().Draw(&output);
}

bool SimpleUI::TestPointInRect(RECT shape)
{
	if (SimpleWindow::GetInstance().GetMousePosX() > shape.X && SimpleWindow::GetInstance().GetMousePosX() < shape.X + shape.Width && SimpleWindow::GetInstance().GetMousePosY() > shape.Y && SimpleWindow::GetInstance().GetMousePosY() < shape.Y + shape.Height)
		return true;
	return false;
}
