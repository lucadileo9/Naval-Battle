# Naval Battle Game

This is a command-line implementation of a Naval Battle game, developed as a project after completing the first year of my Computer Science degree. The purpose of this project was to apply the knowledge gained from Programming I and Programming II courses.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Clean](#clean)
- [Future Developments](#future-developments)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Naval Battle game allows players to engage in a strategic battle on a grid-based board. Each player has their own grid and an opponent's grid. The game operates entirely through the command line, providing a straightforward and engaging user experience. 

**Note:** Currently, the game is available only in Italian, but future developments may include an English version.

## Features

- Two players can compete against each other.
- Each player has a private grid and an opponent grid.
- Players take turns to attack opponent's grid locations.
- Scoring system to keep track of players' points.

## Installation

To compile and run the game on your local machine, follow these steps:

1. **Clone the repository:**
   ```bash
   git clone https://github.com/lucadileo9/Naval-Battle.git
   cd battaglia_navale
   ```

2. **Install dependencies:**
   Make sure you have a C++ compiler installed (like g++) on your system.

3. **Compile the game:**
   Use the provided Makefile to compile the project:
   ```bash
   make
   ```
4. **Run the game:**
   After compilation, execute the game with:
   ```bash
   ./battaglia_navale
   ```

Alternatively, you can run the executable directly:
  ```bash
   make run
   ```
## Usage

- Launch the game from the command line.
- Follow the prompts to enter player names and make moves.
- The game will display the current state of the grids and scores after each turn.

## Clean Up
To remove compiled object files and the executable, run:
 ```bash
   make clean
   ```
This command will delete all .o files and the executable to keep your workspace tidy.

## Future Developments

- Translation of the game interface and instructions into English.
- Adding more game features and modes, such as different grid sizes and ship types.
- Implementing an AI opponent for single-player mode.

## Contributing

Contributions are welcome! If you have suggestions for improvements or bug fixes, please create an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
