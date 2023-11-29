# C_BackGammon

In this repository, I store all the files of my Backgammon project from university. All of the code is written in C++. However, I had to use C features to open the file or define constants (instead of using const..., I had to use #define...). This was a requirement for this particular project. 

### Database

You have your own database where you can add and delete players. You can also see the player's points (Hall Of Fame). 

### AI bots

You can also play with two AI bots (they have different playing strategies) or make them play against each other. 

### Saving each state of the game

Each state of the game is saved to the file, and after the game, you are able to go into visualization mode and see each state of the game from the beginning to the end. You can also go one state forward or one state backward, so you are able to analyze your games!

Saving file format: 
N 0 0
P 0 0
D 0 0
A 0 0
R 0 0
R 0 1
B 5 0
B 5 1

Where:
**N** -> indicates new state of the game
**P** -> indicates players points
**D** -> indicates removed pawns for each player
**A** -> indicates pawns on bar for each player
**B** -> indicates position (column, row) for B pawns
**R** -> indicates position (column, row) for R pawns

# C_Backgammon

This repository houses all the files for my university Backgammon project, coded entirely in C++. While the primary language is C++, certain features, such as file opening and constant definition, adhere to C conventions using #define instead of const.

### Database
Manage your player database with the ability to add and delete players. The player's points are visible in the Hall of Fame.

### AI Bots
Engage in games with two AI bots, each employing distinct playing strategies. Alternatively, let them face off against each other.

### Saving Each State of the Game
Every game state is meticulously saved to a file. After completing a game, delve into visualization mode to review each state from inception to conclusion. Navigate forward or backward one state at a time, empowering you to conduct thorough game analyses.

### Saving File Format

```
N 0 0
P 0 0
D 0 0
A 0 0
R 0 0
R 0 1
B 5 0
B 5 1
```

**N:** Indicates a new state of the game.

**P:** Indicates player points.

**D:** Indicates removed pawns for each player.

**A:** Indicates pawns on the bar for each player.

**B:** Indicates the position (column, row) for B pawns.

**R:** Indicates the position (column, row) for R pawns.
