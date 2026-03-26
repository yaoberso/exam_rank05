#ifndef LIFE_H
# define LIFE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_game
{
    int     width;
    int     height;
    int     iterations;
    char    **board;
    int     x;       // Position horizontale du stylo
    int     y;       // Position verticale du stylo
    int     draw;    // État du stylo (0 = levé, 1 = baissé)
} t_game;

#endif