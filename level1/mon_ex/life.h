#ifndef LIFE_HPP
#define LIFE_HPP
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_game {
    int height;
    int width;
    int iterations;
    int x;
    int y;
    char **map;
    int draw;
} t_game;

#endif