/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** wall
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    init_wall(t_game *game)
{
    t_paramwall opt;
    t_paramwall wall1;
    t_paramwall cityl;

    game->allwall = init_list_wall();
    opt.pos.x = 0;
    opt.pos.y = 2519;
    opt.size.x = 1000;
    opt.size.y = 120;
    wall1.pos.x = 0;
    wall1.pos.y = 2359;
    wall1.size.x = 254;
    wall1.size.y = 166;
    cityl.pos.x = 0;
    cityl.pos.y = 1521;
    cityl.size.x = 81;
    cityl.size.y = 1400;
    game->allwall = add_wall(game->allwall, &opt);
    game->allwall = add_wall(game->allwall, &wall1);
    game->allwall = add_wall(game->allwall, &cityl);
    more_wall(game);
}