/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** destroymob
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    mob1_movement(t_list_mob *allmob)
{
    t_mob *mobs = allmob->first;
    sfFloatRect box;

    while (mobs != NULL) {
        box = sfSprite_getGlobalBounds(mobs->mobs);
        if (mobs->step == 0) {
            if (box.top < 2060 && box.left > 730 && mobs->step == 0) {
                mobs->mov.x = 0;
                mobs->mov.y = 1;
                mobs->orientation = SOUTH;
                sfSprite_move(mobs->lifes, mobs->mov);
                sfSprite_move(mobs->mobs, mobs->mov);
                sfSprite_move(mobs->stats, mobs->mov);
            } else 
                mobs->step = 1;
        }
        if (mobs->step == 1) {
            if (box.left > 302 && box.top > 2000 && mobs->step == 1) {
                mobs->mov.x = -1;
                mobs->mov.y = 0;
                mobs->orientation = WEST;
                sfSprite_move(mobs->lifes, mobs->mov);
                sfSprite_move(mobs->mobs, mobs->mov);
                sfSprite_move(mobs->stats, mobs->mov);
            } else
                mobs->step = 2;
        }
        if (mobs->step == 2) {
            if (box.top > 1848 && box.left <= 302 && mobs->step == 2) {
                mobs->mov.x = 0;
                mobs->mov.y = -1;
                mobs->orientation = NORTH;
                sfSprite_move(mobs->lifes, mobs->mov);
                sfSprite_move(mobs->mobs, mobs->mov);
                sfSprite_move(mobs->stats, mobs->mov);
            } else
                mobs->step = 3;
        }
        if (mobs->step == 3) {
            if (box.left < 736 && box.top > 1840 && mobs->step == 3) {
                mobs->mov.x = 1;
                mobs->mov.y = 0;
                mobs->orientation = EST;
                sfSprite_move(mobs->lifes, mobs->mov);
                sfSprite_move(mobs->mobs, mobs->mov);
                sfSprite_move(mobs->stats, mobs->mov);
            } else
                mobs->step = 0;
        }
		mobs = mobs->next;
    }
    return;
}

void    destroy_mob(t_list_mob *allmob)
{
    t_mob *mob = allmob->first;
    t_mob *tmp;

    while (mob != NULL) {
        tmp = mob->next;
        sfClock_destroy(mob->clock);
        sfSprite_destroy(mob->mobs);
        sfMusic_destroy(mob->scream);
        sfTexture_destroy(mob->mob);
        sfSprite_destroy(mob->lifes);
        sfTexture_destroy(mob->life);
        sfSprite_destroy(mob->stats);
        sfTexture_destroy(mob->stat);
        free(mob);
        mob = tmp;
    }
}