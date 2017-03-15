#pragma once
#include <SFML/Graphics.hpp>
#include <cinttypes>

using namespace sf;

class SimpleWindow
{
private:
	RenderWindow m_Window;
	int32_t m_MouseX;
	int32_t m_MouseY;
	SimpleWindow() {}
public:
	static SimpleWindow& GetInstance()
	{
		static SimpleWindow *instance = new SimpleWindow();
		return *instance;
	}
	SimpleWindow& Startup();
	inline SimpleWindow& SetSize(int32_t width, int32_t height) { m_Window.setSize(Vector2u(width, height)); }
	inline SimpleWindow& SetTitle(std::string title) { m_Window.setTitle(title); }
	SimpleWindow& Update();
	SimpleWindow& Clear();
	SimpleWindow& Draw(Drawable *sprite);
	bool ShouldWindowClose();
	bool GetMouseButtonState(Mouse::Button btn);
	inline int32_t GetMousePosX() const { return m_MouseX; }
	inline int32_t GetMousePosY() const { return m_MouseY; }
};