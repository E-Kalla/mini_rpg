/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** wall_manager2
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    more_wall10(t_game *game)
{
    t_paramwall pink4;

    pink4.pos.x = 160;
    pink4.pos.y = 1594;
    pink4.size.x = 130;
    pink4.size.y = 40;
    game->allwall = add_wall(game->allwall, &pink4);
}

void    more_wall9(t_game *game)
{
    t_paramwall bush5;
    t_paramwall bush6;
    t_paramwall woodwater;

    woodwater.pos.x = 318;
    woodwater.pos.y = 2318;
    woodwater.size.x = 66;
    woodwater.size.y = 34;
    game->allwall = add_wall(game->allwall, &woodwater);
    bush6.pos.x = 128;
    bush6.pos.y = 2294;
    bush6.size.x = 382;
    bush6.size.y = 17;
    game->allwall = add_wall(game->allwall, &bush6);
    bush5.pos.x = 269;
    bush5.pos.y = 2008;
    bush5.size.x = 17;
    bush5.size.y = 216;
    game->allwall = add_wall(game->allwall, &bush5);
    more_wall10(game);
}

void    more_wall8(t_game *game)
{
    t_paramwall pink2;
    t_paramwall pink3;
    t_paramwall bush4;

    bush4.pos.x = 127;
    bush4.pos.y = 2008;
    bush4.size.x = 17;
    bush4.size.y = 216;
    game->allwall = add_wall(game->allwall, &bush4);
    pink2.pos.x = 863;
    pink2.pos.y = 1726;
    pink2.size.x = 37;
    pink2.size.y = 37;
    game->allwall = add_wall(game->allwall, &pink2);
    pink3.pos.x = 863;
    pink3.pos.y = 1790;
    pink3.size.x = 37;
    pink3.size.y = 37;
    game->allwall = add_wall(game->allwall, &pink3);
    more_wall9(game);

}

void    more_wall7(t_game *game)
{
    t_paramwall gbush2;
    t_paramwall gbush3;
    t_paramwall pink1;

    pink1.pos.x = 863;
    pink1.pos.y = 1660;
    pink1.size.x = 37;
    pink1.size.y = 37;
    game->allwall = add_wall(game->allwall, &pink1);
    gbush3.pos.x = 752;
    gbush3.pos.y = 1624;
    gbush3.size.x = 16;
    gbush3.size.y = 104;
    game->allwall = add_wall(game->allwall, &gbush3);
    gbush2.pos.x = 480;
    gbush2.pos.y = 1624;
    gbush2.size.x = 288;
    gbush2.size.y = 5;
    game->allwall = add_wall(game->allwall, &gbush2);
    more_wall8(game);
}

void    more_wall6(t_game *game)
{
    t_paramwall doublehouse;
    t_paramwall ghousethree;
    t_paramwall gbush1;

    gbush1.pos.x = 318;
    gbush1.pos.y = 1624;
    gbush1.size.x = 114;
    gbush1.size.y = 5;
    game->allwall = add_wall(game->allwall, &gbush1);
    ghousethree.pos.x = 348;
    ghousethree.pos.y = 1661;
    ghousethree.size.x = 70;
    ghousethree.size.y = 89;
    game->allwall = add_wall(game->allwall, &ghousethree);
    doublehouse.pos.x = 576;
    doublehouse.pos.y = 1646;
    doublehouse.size.x = 162;
    doublehouse.size.y = 89;
    game->allwall = add_wall(game->allwall, &doublehouse);
    more_wall7(game);
}