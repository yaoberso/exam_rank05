#include "life.h"

char **alloc_map(int height, int width)
{
    char **map = (char **)malloc(height * sizeof(char *));
    if (!map)
    {
        return (NULL);
    }
    for(int i = 0; i < height; i++)
    {
        map[i] = (char *)malloc(width * sizeof(char));
        if (!map[i])
        {
            free_map(map);
            return (NULL);
        }
        for(int j = 0; j < width - 1; j++)
            map[i][j] = '0';
    }
    return (map);
}

int main(int argc, char **argv)
{
    t_game game;
    if (argc != 4)
    {
        return (1);
    }
    game->height = atoi(argv[1]);
    game->width = atoi(argv[2]);
    game->iterations = atoi(argv[3]);
    game->x = 0;
    game->y = 0;
    game->draw = 0;

    if (game->height <= 0 || game->width <= 0 || game->iterations < 0)
    {
        return (0);
    }
    game->map = alloc_map(game->height, game->width);
}