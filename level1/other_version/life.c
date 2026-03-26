#include "life.h"

// -----------------------------------------------------------------------------
// GESTION DE LA MÉMOIRE
// -----------------------------------------------------------------------------

void free_board(char **board, int height)
{
    if (!board)
        return;
    for (int y = 0; y < height; y++)
    {
        if (board[y])
            free(board[y]);
    }
    free(board);
}

char **alloc_board(int width, int height)
{
    char **board = (char **)malloc(sizeof(char *) * height);
    if (!board)
        return (NULL);
    for (int y = 0; y < height; y++)
    {
        board[y] = (char *)malloc(sizeof(char) * width);
        if (!board[y])
        {
            free_board(board, y);
            return (NULL);
        }
        for (int x = 0; x < width; x++)
            board[y][x] = ' '; // Initialise avec des espaces (cellules mortes)
    }
    return (board);
}

// -----------------------------------------------------------------------------
// LECTURE DE L'ENTRÉE ET DESSIN
// -----------------------------------------------------------------------------

void process_input(t_game *game)
{
    char c;

    // read est autorisé pour lire sur l'entrée standard (0) caractère par caractère
    while (read(STDIN_FILENO, &c, 1) > 0)
    {
        if (c == 'w' && game->y > 0)
            game->y--;
        else if (c == 's' && game->y < game->height - 1)
            game->y++;
        else if (c == 'a' && game->x > 0)
            game->x--;
        else if (c == 'd' && game->x < game->width - 1)
            game->x++;
        else if (c == 'x')
            game->draw = !(game->draw); // Alterne entre 0 et 1

        // Si le stylo est baissé, on dessine une cellule vivante 'O' (lettre majuscule)
        if (game->draw)
            game->board[game->y][game->x] = 'O';
    }
}

// -----------------------------------------------------------------------------
// LOGIQUE DU JEU DE LA VIE
// -----------------------------------------------------------------------------

int count_neighbors(t_game *game, int x, int y)
{
    int count = 0;

    // Parcourt un carré de 3x3 autour de la cellule
    for (int dy = -1; dy <= 1; dy++)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            if (dx == 0 && dy == 0)
                continue; // On ne se compte pas soi-même
            
            int nx = x + dx;
            int ny = y + dy;
            
            // Vérifie qu'on ne sort pas de la grille
            if (nx >= 0 && nx < game->width && ny >= 0 && ny < game->height)
            {
                if (game->board[ny][nx] == 'O')
                    count++;
            }
        }
    }
    return (count);
}

int simulate(t_game *game)
{
    char **next_board = alloc_board(game->width, game->height);
    if (!next_board)
        return (0);

    for (int y = 0; y < game->height; y++)
    {
        for (int x = 0; x < game->width; x++)
        {
            int neighbors = count_neighbors(game, x, y);
            
            if (game->board[y][x] == 'O')
            {
                // Règle de survie : 2 ou 3 voisins
                if (neighbors == 2 || neighbors == 3)
                    next_board[y][x] = 'O';
                else
                    next_board[y][x] = ' '; // Meurt
            }
            else
            {
                // Règle de naissance : exactement 3 voisins
                if (neighbors == 3)
                    next_board[y][x] = 'O';
                else
                    next_board[y][x] = ' '; // Reste morte
            }
        }
    }

    // On remplace l'ancienne grille par la nouvelle
    free_board(game->board, game->height);
    game->board = next_board;
    return (1);
}

// -----------------------------------------------------------------------------
// AFFICHAGE ET MAIN
// -----------------------------------------------------------------------------

void print_board(t_game *game)
{
    for (int y = 0; y < game->height; y++)
    {
        for (int x = 0; x < game->width; x++)
        {
            putchar(game->board[y][x]);
        }
        putchar('\n');
    }
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 4)
        return (1);

    // Initialisation
    game.width = atoi(argv[1]);
    game.height = atoi(argv[2]);
    game.iterations = atoi(argv[3]);
    game.x = 0;
    game.y = 0;
    game.draw = 0;

    // Sécurité de base
    if (game.width <= 0 || game.height <= 0 || game.iterations < 0)
        return (1);

    game.board = alloc_board(game.width, game.height);
    if (!game.board)
        return (1);

    // Étape 1 : Lire l'entrée et tracer l'état initial
    process_input(&game);

    // Étape 2 : Lancer la simulation pour le nombre d'itérations demandé
    for (int i = 0; i < game.iterations; i++)
    {
        if (!simulate(&game))
        {
            free_board(game.board, game.height);
            return (1);
        }
    }

    // Étape 3 : Afficher et nettoyer
    print_board(&game);
    free_board(game.board, game.height);

    return (0);
}