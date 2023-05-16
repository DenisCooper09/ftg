# Fractal Tree Generator

Fractal tree generator written in C++ and SFML.

## Algorithm

The fractal tree algorithm is a recursive algorithm that generates a tree-like fractal shape. Here's how it works:

1. Start with a single line segment (the "trunk") that represents the main stem of the tree.
2. At the end of the trunk, create two new line segments (the "branches") at a certain angle, length, and thickness.
   These branches will be the first level of the tree.
3. For each branch, repeat step 2 recursively. That is, at the end of each branch, create two new branches at a certain
   angle, length, and thickness. This process is repeated until a certain depth or number of iterations is reached, or
   until the length or thickness of the branches becomes too small to see.
4. As the tree branches get smaller and more numerous with each iteration, the overall shape of the tree becomes more
   complex and "fractal" in nature.

## Documentation

### Function definition

```c++
[[maybe_unused]] bool draw_fractal_tree(int depth,
                                        double length,
                                        double length_divider,
                                        double angle,
                                        double angle_modifier,
                                        float thickness,
                                        sf::Vector2<double> start);
```

This function generates and draws a fractal tree using the specified parameters. The tree is drawn using the SFML
library. The success status indicates whether the tree was successfully drawn or not.

`depth` The depth of the fractal tree. Determines the number of recursive iterations.

`length` The length of the current branch of the fractal tree.

`length_divider` The factor by which the length of the branches decreases with each iteration.

`angle` The angle at which the branches of the tree are drawn.

`angle_modifier` The value by which the angle is modified at each recursive step.

`thickness` The thickness of the branches.

`start` The starting position of the branch.

`return` true if the fractal tree was successfully drawn, false otherwise.

## Experiments

### Basic Tree

Let's take a look at this configuration and imagine it as a standard configuration. Next, we will change the parameters
one by one to get different results.

```c++
fractal_tree_generator.draw_fractal_tree(10,
                                         200.0,
                                         0.7,
                                         -90,
                                         25.0,
                                         1.0f,
                                         {static_cast<double>(WINDOW_WIDTH) * 0.5, WINDOW_HEIGHT - 50});
```

![image_1](images/image_1.png)

### Depth

> The depth of the fractal tree. Determines the number of recursive iterations.

```c++
fractal_tree_generator.draw_fractal_tree(15,
                                         200.0,
                                         0.7,
                                         -90,
                                         25.0,
                                         1.0f,
                                         {static_cast<double>(WINDOW_WIDTH) * 0.5, WINDOW_HEIGHT - 50});
```

![image_2](images/image_2.png)

### Length

> The length of the current branch of the fractal tree.

```c++
fractal_tree_generator.draw_fractal_tree(10,
                                         100.0,
                                         0.7,
                                         -90,
                                         25.0,
                                         1.0f,
                                         {static_cast<double>(WINDOW_WIDTH) * 0.5, WINDOW_HEIGHT - 50});
```

![image_3](images/image_3.png)

### Length divider

> The factor by which the length of the branches decreases with each iteration.

```c++
fractal_tree_generator.draw_fractal_tree(10,
                                         200.0,
                                         0.5,
                                         -90,
                                         25.0,
                                         1.0f,
                                         {static_cast<double>(WINDOW_WIDTH) * 0.5, WINDOW_HEIGHT - 50});
```

![image_4](images/image_4.png)

### Angle

> The angle at which the branches of the tree are drawn.

```c++
fractal_tree_generator.draw_fractal_tree(10,
                                         200.0,
                                         0.7,
                                         -45,
                                         25.0,
                                         1.0f,
                                         {static_cast<double>(WINDOW_WIDTH) * 0.5, WINDOW_HEIGHT - 50});
```

![image_5](images/image_5.png)

### Angle modifier

> The value by which the angle is modified at each recursive step.

```c++
fractal_tree_generator.draw_fractal_tree(10,
                                         200.0,
                                         0.7,
                                         -90,
                                         45.0,
                                         1.0f,
                                         {static_cast<double>(WINDOW_WIDTH) * 0.5, WINDOW_HEIGHT - 50});
```

![image_6](images/image_6.png)

```c++
fractal_tree_generator.draw_fractal_tree(10,
                                         200.0,
                                         0.7,
                                         -90,
                                         90.0,
                                         1.0f,
                                         {static_cast<double>(WINDOW_WIDTH) * 0.5, WINDOW_HEIGHT - 50});
```

![image_7](images/image_7.png)

### Thickness

> The thickness of the branches.

```c++
fractal_tree_generator.draw_fractal_tree(10,
                                         200.0,
                                         0.7,
                                         -90,
                                         25.0,
                                         5.0f,
                                         {static_cast<double>(WINDOW_WIDTH) * 0.5, WINDOW_HEIGHT - 50});
```

![image_8](images/image_8.png)
