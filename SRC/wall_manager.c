/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** wall_manager
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    more_wall5(t_game *game)
{
    t_paramwall house7;
    t_paramwall threeh7;
    t_paramwall greenhouse;

    greenhouse.pos.x = 480;
    greenhouse.pos.y = 1662;
    greenhouse.size.x = 100;
    greenhouse.size.y = 68;
    game->allwall = add_wall(game->allwall, &greenhouse);
    house7.pos.x = 604;
    house7.pos.y = 2316;
    house7.size.x = 102;
    house7.size.y = 138;
    game->allwall = add_wall(game->allwall, &house7);
    threeh7.pos.x = 846;
    threeh7.pos.y = 2318;
    threeh7.size.x = 68;
    threeh7.size.y = 84;
    game->allwall = add_wall(game->allwall, &threeh7);
    more_wall6(game);
}

void    more_wall4(t_game *game)
{
    t_paramwall house4;
    t_paramwall house5;
    t_paramwall house6;

    house4.pos.x = 590;
    house4.pos.y = 2122;
    house4.size.x = 100;
    house4.size.y = 89;
    game->allwall = add_wall(game->allwall, &house4);
    house5.pos.x = 780;
    house5.pos.y = 2110;
    house5.size.x = 100;
    house5.size.y = 89;
    game->allwall = add_wall(game->allwall, &house5);
    house6.pos.x = 414;
    house6.pos.y = 2338;
    house6.size.x = 68;
    house6.size.y = 66;
    game->allwall = add_wall(game->allwall, &house6);
    more_wall5(game);
}

void    more_wall3(t_game *game)
{
    t_paramwall house2;
    t_paramwall house3;
    t_paramwall bhouse3;

    house2.pos.x = 798;
    house2.pos.y = 1902;
    house2.size.x = 105;
    house2.size.y = 89;
    game->allwall = add_wall(game->allwall, &house2);
    house3.pos.x = 350;
    house3.pos.y = 2124;
    house3.size.x = 100;
    house3.size.y = 100;
    game->allwall = add_wall(game->allwall, &house3);
    bhouse3.pos.x = 442;
    bhouse3.pos.y = 2143;
    bhouse3.size.x = 37;
    bhouse3.size.y = 70;
    game->allwall = add_wall(game->allwall, &bhouse3);
    more_wall4(game);
}

void    more_wall2(t_game *game)
{
    t_paramwall house1;
    t_paramwall right;
    t_paramwall uper;

    right.pos.x = 0;
    right.pos.y = 1594;
    right.size.x = 1300;
    right.size.y = 1;
    game->allwall = add_wall(game->allwall, &right);
    right.pos.x = 950;
    right.pos.y = 1590;
    right.size.x = 150;
    right.size.y = 1000;
    game->allwall = add_wall(game->allwall, &right);
    house1.pos.x = 150;
    house1.pos.y = 1838;
    house1.size.x = 111;
    house1.size.y = 75;
    game->allwall = add_wall(game->allwall, &house1);
    more_wall3(game);
}

void    more_wall(t_game *game)
{
    t_paramwall cityn;
    t_paramwall cityne;
    t_paramwall cityne2;

    cityne2.pos.x = 480;
    cityne2.pos.y = 1774;
    cityne2.size.x = 351;
    cityne2.size.y = 61;
    cityne.pos.x = 322;
    cityne.pos.y = 1758;
    cityne.size.x = 108;
    cityne.size.y = 81;
    cityn.pos.x = 0;
    cityn.pos.y = 1675;
    cityn.size.x = 262;
    cityn.size.y = 90;
    game->allwall = add_wall(game->allwall, &cityn);
    game->allwall = add_wall(game->allwall, &cityne);
    game->allwall = add_wall(game->allwall, &cityne2);
    more_wall2(game);
}