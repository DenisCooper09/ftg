#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

#include "fractal_tree_generator.h"

#define CAMERA_SPEED 10

int main() {
    std::cout << " ////////////////////////////////////" << std::endl;
    std::cout << " ////// Fractal Tree Generator //////" << std::endl;
    std::cout << " ////////////////////////////////////" << std::endl;
    std::cout << " Controls:" << std::endl;
    std::cout << " [ SPACE ] - Generate new random tree." << std::endl;
    std::cout << " [ S ]     - Save fractal tree as PNG image "
                 "(After restarting the program old screenshots will be rewritten!!!)." << std::endl;
    std::cout << " [ UP ]    - Move camera up." << std::endl;
    std::cout << " [ DOWN ]  - Move camera down." << std::endl;
    std::cout << " [ LEFT ]  - Move camera left." << std::endl;
    std::cout << " [ RIGHT ] - Move camera right." << std::endl;
    std::cout << " [ + ]     - Zoom in." << std::endl;
    std::cout << " [ - ]     - Zoom out." << std::endl << std::endl;
    std::cout << " In future updates Fractal Tree Generator will get GUI!";

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    constexpr int WINDOW_WIDTH = 1200;
    constexpr int WINDOW_HEIGHT = 800;

    sf::RenderWindow window(
            {WINDOW_WIDTH, WINDOW_HEIGHT},
            "Fractal Tree Generator",
            sf::Style::Close,
            settings
    );

    sf::View view(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> random_depth(3, 15);
    std::uniform_int_distribution<int> random_color(0, 255);
    std::uniform_real_distribution<double> random_length(50.0, 300.0);
    std::uniform_real_distribution<double> random_length_divider(0.1, 0.8);
    std::uniform_real_distribution<double> random_angle_modifier(10.0, 300.0);
    std::uniform_real_distribution<float> random_thickness(1.0f, 10.0f);

    int depth;
    double length, length_divider, angle_modifier;
    float thickness;
    sf::Color color(0, 0, 0), color_modifier(10, 10, 10);
    bool angle_randomizer_flag = true;

    int screenshot_number = 0;

    fractal_tree_generator fractal_tree_generator(window);

    while (window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Left:
                            view.move(-CAMERA_SPEED, 0);
                            break;
                        case sf::Keyboard::Right:
                            view.move(CAMERA_SPEED, 0);
                            break;
                        case sf::Keyboard::Up:
                            view.move(0, -CAMERA_SPEED);
                            break;
                        case sf::Keyboard::Down:
                            view.move(0, CAMERA_SPEED);
                            break;
                        case sf::Keyboard::Equal:
                            view.zoom(0.9f);
                            break;
                        case sf::Keyboard::Dash:
                            view.zoom(1.1f);
                            break;
                        default:
                            break;
                    }
                    break;
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::S: {
                            sf::Texture texture;
                            texture.create(window.getSize().x, window.getSize().y);
                            texture.update(window);

                            sf::Image screenshot = texture.copyToImage();

                            char filename[256];
                            snprintf(filename, sizeof(filename), "screenshot%d.png", screenshot_number);

                            if (screenshot.saveToFile(filename)) {
                                std::cout << "Screenshot saved!" << std::endl;
                                screenshot_number++;
                            } else {
                                std::cerr << "Failed to save the screenshot." << std::endl;
                            }
                            break;
                        }
                        case sf::Keyboard::Space:
                            depth = random_depth(gen);
                            length = random_length(gen);
                            length_divider = random_length_divider(gen);
                            angle_modifier = random_angle_modifier(gen);
                            thickness = random_thickness(gen);
                            color.r = random_color(gen);
                            color.g = random_color(gen);
                            color.b = random_color(gen);
                            color_modifier.r = random_color(gen);
                            color_modifier.g = random_color(gen);
                            color_modifier.b = random_color(gen);
                            angle_randomizer_flag = true;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        window.setView(view);
        window.clear(sf::Color::Black);

        fractal_tree_generator.draw_fractal_tree(
                depth,
                length,
                length_divider,
                -90,
                angle_modifier,
                -10,
                10,
                angle_randomizer_flag,
                thickness,
                -0.75f,
                {
                        static_cast<double>(WINDOW_WIDTH) * 0.5,
                        WINDOW_HEIGHT - 50
                },
                color,
                color_modifier
        );

        angle_randomizer_flag = false;

        window.display();
    }

    return EXIT_SUCCESS;
}
