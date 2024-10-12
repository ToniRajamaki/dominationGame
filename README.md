# 🏞️ Pirkanmaan Valloitus

Welcome to the **Pirkanmaan Valloitus** project! This is a strategic resource management game developed in C++ with Qt Creator as part of a group project. The game involves strategic decision-making, where players manage resources, cooperate, or compete against each other or AI to build a nuclear plant and win the game. The game features a randomly generated map each time you play.

[![C++](https://img.shields.io/badge/C++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/) [![Qt Creator](https://img.shields.io/badge/Qt%20Creator-%23327BBD.svg?style=for-the-badge&logo=qt&logoColor=white)](https://www.qt.io/product/development-tools) [![GitHub JoonasPel](https://img.shields.io/badge/GitHub-JoonasPel-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)](https://github.com/JoonasPel)

## 🌐 Project Overview

The **Pirkanmaan Valloitus** game is designed to bring a strategic experience where up to 4 players can either cooperate or compete. The game’s objective is to build a nuclear plant before other players. The map is randomly generated, ensuring a fresh challenge each game session. Developed as a collaborative project, it explores the depth of resource management and strategic planning.

<img src="https://github.com/ToniRajamaki/folio2/blob/main/public/assets/project-thumbnails/pirkanmaanvalloitus-thumbnail.png?raw=true" alt="Pirkanmaan Valloitus Screenshot" />

## 🛠️ Technologies Used

<p align="center">
  <img src="https://img.shields.io/badge/C++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++" />
  <img src="https://img.shields.io/badge/Qt%20Creator-%23327BBD.svg?style=for-the-badge&logo=qt&logoColor=white" alt="Qt Creator" />
</p>

## 🌟 Key Features

- **Strategic Gameplay**: Manage resources strategically to win by building a nuclear plant.
- **Multiplayer Support**: Play with up to 4 players—either cooperatively or against each other or the AI.
- **Random Map Generation**: Every game features a different map, providing a unique experience.
- **Resource Management**: Deep mechanics that challenge players to manage resources efficiently.

## 📜 Game Rules
  
  ### Introduction

  Players take on the role of businesspersons from the 1950s who have heard about a new, incredibly efficient energy source: Nuclear Energy. Both business moguls are doing everything in their power to acquire the necessary resources to build the first nuclear power plant in Pirkanmaa and create a monopoly. The game world is set in the rugged landscapes of Pirkanmaa, which include arid deserts, dense forests, and towering mountains. The environment is also known for its fish-rich waters and vast prairies.

  ### Game Rules

  The game involves two players whose names can be defined in the settings window. The game uses a turn-based system: each time a player ends their turn, they generate resources. In the settings window, it is also possible to set a time-based turn system, where turns switch at given time intervals, or players can choose to end their turn manually.

  **Tiles** have an ownership feature. A player claims a tile by placing a building or a [![Worker](https://img.shields.io/badge/Worker-%23FF6F00.svg?style=flat-square)](#) on it. Players cannot place their worker or building on a tile owned by the opponent. To hire a worker or build a structure, a player must have sufficient resources. Workers or buildings can only be placed on tiles adjacent to tiles that already have a building owned by the player.

  ### Gameplay

  The game features five different types of **tiles**:

  - **[![Grassland](https://img.shields.io/badge/Grassland-%239acd32.svg?style=flat-square)](#)**: The most common tile. A good source of food.
  - **[![Forest](https://img.shields.io/badge/Forest-%23006400.svg?style=flat-square)](#)**: A great source of wood.
  - **[![Rocky Mountains](https://img.shields.io/badge/Rocky%20Mountains-%238B4513.svg?style=flat-square)](#)**: A rich source of stone and ore.
  - **[![Water](https://img.shields.io/badge/Water-%2300BFFF.svg?style=flat-square)](#)**: An excellent source of food and money. Only one building can be constructed on this tile.
  - **[![Desert](https://img.shields.io/badge/Desert-%23F4A460.svg?style=flat-square)](#)**: Offers very poor resources and is best avoided.

  ### Buildings

  The game features five different types of **buildings**: Outpost, Farm, Mine, Headquarters, and Nuclear Plant.

  - **Outpost**: When an Outpost is built, the player gains control over a 5x5 area and places a soldier on each tile. Each player can build only one Outpost.
  - **Nuclear Plant**: Constructing a Nuclear Plant ends the game, and the builder is declared the winner.
  - **Headquarters**: Each player starts with a Headquarters, which serves as the starting point. The player's goal is to gather enough resources to build the Nuclear Plant and win the game.

  Players should strategically place buildings to create paths to valuable tiles based on the resources they need.

  ### Workers

  There are three different types of **workers**: [![Basic Worker](https://img.shields.io/badge/Basic%20Worker-%23FF6F00.svg?style=flat-square)](#), [![Advanced Worker](https://img.shields.io/badge/Advanced%20Worker-%234CAF50.svg?style=flat-square)](#), and [![Elite Worker](https://img.shields.io/badge/Elite%20Worker-%23FFD700.svg?style=flat-square)](#).
  - **Basic Worker**: The cheapest to hire and maintain but the least effective.
  - **Advanced Worker**: More efficient than the Basic Worker but more costly.
  - **Elite Worker**: The most effective but also the most expensive to hire and maintain.

  |           | BASIC        | ADVANCED     | ELITE        |
  |-----------|--------------|--------------|--------------|
  | Money     | 10           | 25           | 50           |
  | Food      | 25           | 35           | 50           |
  | Maintenance (Money) | 1  | 2            | 3            |
  | Maintenance (Food)  | 1  | 2            | 3            |

  ### Turn System

  If a time limit for turns is set, the player can see how much time remains before their turn ends in the bottom right corner of the game window. If the time is set to 0, the turn ends only when the player presses the "END TURN" button.

  ### Additional Rules

  - If a player's production is negative, their resources can fall below zero, making it very challenging to win the game.
  - Players cannot remove a building or worker, making the game more difficult since every move is final.
  - During the game, players can check their resources in the top right corner of the game window. The resources earned each turn are displayed on the right.
  - Players can take advantage of Pat's daily offers.



## 🗺️ Roadmap

- [x] **Multiplayer Mechanics**: Implement multiplayer gameplay for up to 4 players.
- [x] **Random Map Generation**: Add randomly generated maps for varied gameplay.
- [ ] **Advanced AI Player**: Improve AI decision-making for a more challenging single-player experience.
- [ ] **Additional Resources**: Introduce new resource types to deepen gameplay.
- [ ] **Visual Enhancements**: Improve the graphical interface for a more polished look.

This project is open-source and available under the [MIT License](LICENSE).

## 🤝 Connect with Us

<p align="left">
  <a href="https://linkedin.com/in/toni-rajam%C3%A4ki-025055283" target="_blank">
    <img src="https://img.shields.io/badge/LinkedIn-Connect-blue?style=for-the-badge&logo=linkedin" alt="LinkedIn Badge" />
  </a>
  <a href="https://github.com/JoonasPel" target="_blank">
    <img src="https://img.shields.io/badge/GitHub-JoonasPel-%23121011.svg?style=for-the-badge&logo=github&logoColor=white" alt="GitHub JoonasPel" />
  </a>
</p>

**Extra Info**: This project was a great experience in collaborative development and strategic game design. We look forward to possibly expanding on the concept further, adding more complexity and polish in the future.
