#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_coordinate
{
    int x;                  // player's x-coordinate
    int y;                  // y-coordinate
}   t_coordinate;

typedef struct s_player
{
    t_coordinate coordinate; // the x,y coordinates of the palyer
    unsigned int moves;     // number of moves the player has made
    int collectibles;       // the numeber of collectibles the player has
}   t_player;

typedef struct s_map
{
    char **grid;    // 2D array representing the map(char value like '1', '0', 'P')
    int width;      // map width (number of columns)
    int height;     // map height (number of rows)
    unsigned int collectibles; // number of collects in the map
    t_coordinate final; // final point of tha map
}   t_map;

typedef struct s_game
{
    void *mlx;          // pointer to the mlx instance
    void *win;          // pointer to the window
    t_player player;    // player struct
    t_map map;          // map struct
    unsigned int moves; // number of moves the player has made
}   t_game;



#endif 