# 42 so_long

## Description

The **so_long** project is a 2D game developed as part of the 42 curriculum. The objective of this project is to create a simple yet engaging game using the **MiniLibX** library, which is a minimalistic graphics library provided by 42. The game involves navigating a character through a map to collect items and reach an exit, all while avoiding obstacles.

This project is designed to help students understand the basics of game development, including rendering graphics, handling user input, and managing game states. It also emphasizes the importance of clean code, efficient memory management, and proper error handling.

## Features

- **Dynamic Map Loading**: The game loads maps from `.ber` files, allowing for customizable levels.
- **Player Movement**: The player can move up, down, left, and right using the arrow keys or `W`, `A`, `S`, `D`.
- **Collectibles**: The player must collect all items scattered across the map before reaching the exit.
- **Win Condition**: The game ends successfully when the player collects all items and reaches the exit.
- **Lose Condition**: The game ends if the player encounters an obstacle (e.g., an enemy).
- **Graphics Rendering**: The game uses the MiniLibX library to render the map, player, items, and exit.
- **Error Handling**: The program handles various errors, such as invalid maps or missing textures, gracefully.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/so_long.git
   ```
2. Navigate to the project directory:
    ```bash
    cd so_long
    ```
3. Compile the project using make:
    ```bash
    make
    ```
4. Run the game with a map file:
    ```bash
    ./so_long maps/map1.ber
    ```
## Usage

    Movement: Use the arrow keys or W, A, S, D to move the player.

    Objective: Collect all items (C) on the map and reach the exit (E).

    Quit: Press ESC or click the close button to exit the game.

## Map Format

The game uses .ber files to define maps. The map format is as follows:

    1: Wall (impassable)

    0: Empty space (passable)

    C: Collectible (item to collect)

    E: Exit (goal to reach)

    P: Player starting position

## Example map:

```bash
  111111111
  1P00000E1
  110C01111
  1000000C1
  111111111
```
## Requirements
    MiniLibX: The project requires the MiniLibX library, which is provided by 42.
    Make: The project uses a Makefile for compilation.
