#include <SFML/Graphics.hpp>

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	constexpr int WINDOW_WIDTH = 1200;
	constexpr int WINDOW_HEIGHT = 800;

	sf::RenderWindow window({WINDOW_WIDTH, WINDOW_HEIGHT},
							"Fractal Tree Generator",
							sf::Style::Close,
							settings);

	while (window.isOpen()) {
		sf::Event event{};

		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}

		window.clear(sf::Color::Black);
		window.display();
	}

	return EXIT_SUCCESS;
}
