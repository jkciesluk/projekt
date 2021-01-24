# Roguelike game

## Projekt z PWI
___
### Game description

Your goal is to free a princess kidnapped by some bad monsters :(
To achieve your goal you have to beat three different levels of a maze,
to get through each level you have to find a way out and unlock it using three keys located on your map.

#### Controls
\W - move up
\S - move down
\A - move left
\D - move right
\P - use potion

##### Symbols
\# - wall
\+ - free space
\@ - player
\P - potion
\K - key
\m - small monster
\M - medium monster
\W - big monster
\D - doors
\E - hatch to the next level


###### How to install:
First, install ncurses:
>sudo apt-get install libncurses5-dev libncursesw5-dev

Then compile using:
>g++ -o roguelike player.cpp enemyAI.cpp basic_ui.cpp gen_map.cpp -lncurses

And run:
>./roguelike
