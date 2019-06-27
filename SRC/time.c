/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** time handling
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    time_handling(t_game *game)
{
    game->timeg = sfClock_getElapsedTime(game->mobspawn);
    game->spawning = game->timeg.microseconds / 100000.0;
}