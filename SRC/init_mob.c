/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** initmob
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    init_mob(t_game *game)
{
    game->allmob = init_list_mob();
}