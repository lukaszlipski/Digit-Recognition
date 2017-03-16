#include "SimpleWindow.h"

SimpleWindow& SimpleWindow::Startup()
{
	m_Window.create(sf::VideoMode(1024, 720), "Handwriting Recognition", Style::Close);
	m_Window.setVerticalSyncEnabled(true);
	return *this;
}

SimpleWindow& SimpleWindow::Update()
{
	m_Window.display();

	m_MouseX = Mouse::getPosition(m_Window).x;
	m_MouseY = Mouse::getPosition(m_Window).y;

	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_Window.close();
	}
	return *this;
}

SimpleWindow& SimpleWindow::Clear()
{
	m_Window.clear(Color(238, 238, 238));
	return *this;
}

SimpleWindow& SimpleWindow::Draw(Drawable* sprite)
{
	m_Window.draw(*sprite);
	return *this;
}

bool SimpleWindow::ShouldWindowClose() const { return !m_Window.isOpen(); }

bool SimpleWindow::GetMouseButtonState(Mouse::Button btn) const { return Mouse::isButtonPressed(btn); }
