/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** spawnmob
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    draw_mob(t_list_mob *allmob, t_game *game)
{
    t_mob *mob = allmob->first;

    while (mob != NULL) {
        if (mob->alive == true) {
            sfRenderWindow_drawSprite(game->gamewindow, mob->lifes, NULL);
            sfRenderWindow_drawSprite(game->gamewindow, mob->mobs, NULL);
            if (game->quest->statsecond == CURRENT)
                sfRenderWindow_drawSprite(game->gamewindow, mob->stats, NULL);
        }
        mob = mob->next;
    }
}

void    configure_mob1(t_parammob *newmob)
{
    newmob->alive = true;
    newmob->pos.x = 733;
    newmob->pos.y = 1852;
    newmob->rect.left = 196;
    newmob->rect.top = 0;
    newmob->rect.width = 24;
    newmob->rect.height = 32;
    newmob->hp = 100;
    newmob->strenght = 20;
    newmob->smart = 0;
    newmob->agility = 1;
    newmob->mana = 0;
    newmob->step = 0;
    newmob->mov.x = 0;
    newmob->mov.y = 0;
    newmob->reclife.top = 2;
    newmob->reclife.left = 3;
    newmob->reclife.height = 4;
    newmob->reclife.width = 39;
}

void    mob_alive(t_list_mob *allmob)
{
    t_mob *mob = allmob->first;

    while (mob != NULL) {
        if (mob->hp <= 0)
            mob->alive = false;
        mob = mob->next;
    }
}

void    mob_manage(t_game *game)
{
    t_parammob newmob;

    if (game->spawning > 100) {
        configure_mob1(&newmob);
        game->allmob = add_mob(game->allmob, &newmob);
        sfClock_restart(game->mobspawn);
    }
    mob_alive(game->allmob);
    mob1_movement(game->allmob);
    mob1_rect(game->allmob);
}