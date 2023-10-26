#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdint>
#include <random>

class [[maybe_unused]] fractal_tree_generator {
private:
    sf::RenderWindow *_window;

public:
    [[maybe_unused]] explicit fractal_tree_generator(sf::RenderWindow &window);

    /**

     @brief Draws a fractal tree recursively and returns the success status.

     This function generates and draws a fractal tree using the specified parameters.
     The tree is drawn using the SFML library.
     The success status indicates whether the tree was successfully drawn or not.

     @param depth The depth of the fractal tree. Determines the number of recursive iterations.
     @param length The length of the current branch of the fractal tree.
     @param length_divider The factor by which the length of the branches decreases with each iteration.
     @param angle The angle at which the branches of the tree are drawn.
     @param angle_modifier The value by which the angle is modified at each recursive step.
     @param thickness The thickness of the branches.
     @param thickness_modifier The value by which the thickness is modified at each recursive step.
     @param start The starting position of the branch.
     @param angle_randomizer_min Min number for random coefficient that will affect angle of the branch each iteration.
     @param angle_randomizer_max Max number for random coefficient that will affect angle of the branch each iteration.
     @param color The color of the branches.
     @param color_modifier The color which will be added up to previous branch's to get a color for a new one.

     @return true if the fractal tree was successfully drawn, false otherwise.

     @remarks The SFML library must be initialized before calling this function,
     and a valid SFML RenderWindow object must be set to the _window member variable of the fractal_tree_generator
     instance.

     @remarks This function assumes that the _window member variable is not null,
     otherwise the tree will not be drawn.

     @remark Repository: https://github.com/DenisCooper09/fractal_tree_generator
    */
    [[maybe_unused]] bool draw_fractal_tree(
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
            sf::Color color_modifier
    );
};
