#include <SFML/Graphics.hpp>
#include "fractal_tree_generator.h"

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	constexpr int WINDOW_WIDTH = 1200;
	constexpr int WINDOW_HEIGHT = 800;

	sf::RenderWindow window({WINDOW_WIDTH, WINDOW_HEIGHT},
							"Fractal Tree Generator",
							sf::Style::Close,
							settings);

	fractal_tree_generator fractal_tree_generator(window);

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

		fractal_tree_generator.draw_fractal_tree(10,
												 200.0,
												 0.7,
												 -90,
												 25.0,
												 1.0f,
												 {
														 static_cast<double>(WINDOW_WIDTH) * 0.5,
														 WINDOW_HEIGHT - 50
												 });

		window.display();
	}

	return EXIT_SUCCESS;
}
