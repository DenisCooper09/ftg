#include "fractal_tree_generator.h"

[[maybe_unused]] fractal_tree_generator::fractal_tree_generator(sf::RenderWindow &window) {
    _window = &window;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

[[maybe_unused]] bool fractal_tree_generator::draw_fractal_tree(
        int depth,
        double length,
        double length_divider,
        double angle,
        double angle_modifier,
        double angle_randomizer_min,
        double angle_randomizer_max,
        bool angle_randomizer_flag,
        float thickness,
        float thickness_modifier,
        sf::Vector2<double> start,
        sf::Color color,
        sf::Color color_modifier) {
    if (_window == nullptr) {
        return false;
    }

    if (depth <= 0) {
        return true;
    }

    sf::RectangleShape line({static_cast<float>(length), thickness});
    line.setFillColor(color);
    line.setPosition({static_cast<float>(start.x), static_cast<float>(start.y)});
    line.setRotation(static_cast<float>(angle));
    _window->draw(line);

    const double ANGLE_IN_RADIANS = angle * M_PI / 180.0f;
    sf::Vector2<double> end = start + sf::Vector2<double>(
            length * std::cos(ANGLE_IN_RADIANS),
            length * std::sin(ANGLE_IN_RADIANS)
    );

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distribution(angle_randomizer_min, angle_randomizer_max);

    draw_fractal_tree(
            depth - 1,
            length * length_divider,
            length_divider,
            angle + angle_modifier + (angle_randomizer_flag ? distribution(gen) : 0.0),
            angle_modifier,
            angle_randomizer_min,
            angle_randomizer_max,
            angle_randomizer_flag,
            thickness + thickness_modifier,
            thickness_modifier,
            end,
            color + color_modifier,
            color_modifier
    );

    draw_fractal_tree(
            depth - 1,
            length * length_divider,
            length_divider,
            angle - angle_modifier - (angle_randomizer_flag ? distribution(gen) : 0.0),
            angle_modifier,
            angle_randomizer_min,
            angle_randomizer_max,
            angle_randomizer_flag,
            thickness + thickness_modifier,
            thickness_modifier,
            end,
            color + color_modifier,
            color_modifier
    );

    return false;
}

#pragma clang diagnostic pop
