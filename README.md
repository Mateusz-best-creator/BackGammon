# C_Backgammon

This repository houses all the files for my university Backgammon project, coded entirely in C++. While the primary language is C++, certain features, such as file opening and constant definition, adhere to C conventions using #define instead of const.

### Database
Manage your player database with the ability to add and delete players. The player's points are visible in the Hall of Fame.

### AI Bots
Engage in games with two AI bots, each employing distinct playing strategies. Alternatively, let them face off against each other.

### Saving Each State of the Game & Visualizing
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

### AI VS AI Folder
Within this directory, I store 5 games featuring AI bots playing against each other. You can utilize the contents of these files to visually explore and analyze the progression and outcomes of these games.
