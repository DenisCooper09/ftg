#include "fractal_tree_generator.h"

[[maybe_unused]] fractal_tree_generator::fractal_tree_generator(sf::RenderWindow &window) {
	_window = &window;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

[[maybe_unused]] bool fractal_tree_generator::draw_fractal_tree(int depth,
																double length,
																double length_divider,
																double angle,
																double angle_modifier,
																float thickness,
																sf::Vector2<double> start) {
	if (_window == nullptr) {
		return false;
	}

	if (depth <= 0) {
		return true;
	}

	sf::RectangleShape line({static_cast<float>(length), thickness});
	line.setFillColor(sf::Color::White);
	line.setPosition({static_cast<float>(start.x), static_cast<float>(start.y)});
	line.setRotation(static_cast<float>(angle));
	_window->draw(line);

	const double ANGLE_IN_RADIANS = angle * M_PI / 180.0f;
	sf::Vector2<double> end = start + sf::Vector2<double>(
			length * std::cos(ANGLE_IN_RADIANS),
			length * std::sin(ANGLE_IN_RADIANS)
	);

	draw_fractal_tree(depth - 1,
					  length * length_divider,
					  length_divider,
					  angle + angle_modifier,
					  angle_modifier,
					  thickness,
					  end);
	draw_fractal_tree(depth - 1,
					  length * length_divider,
					  length_divider,
					  angle - angle_modifier,
					  angle_modifier,
					  thickness,
					  end);

	return false;
}

#pragma clang diagnostic pop
