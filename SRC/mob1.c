/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** mob1
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    move_up_mob(t_mob *mobs)
{
    mobs->timer = sfClock_getElapsedTime(mobs->clock);
    mobs->second = mobs->timer.microseconds / 1000000.0;
    if (mobs->rect.top != 96 || mobs->rect.left >= 261) {
        mobs->rect.top = 96;
        mobs->rect.left = 196;
    }
    if (mobs->second > 0.4) {
        mobs->rect.left += 33;
        sfClock_restart(mobs->clock);
    }
}

void    move_down_mob(t_mob *mobs)
{
    mobs->timer = sfClock_getElapsedTime(mobs->clock);
    mobs->second = mobs->timer.microseconds / 1000000.0;
    if (mobs->rect.top != 1 || mobs->rect.left >= 261) {
        mobs->rect.top = 1;
        mobs->rect.left = 196;
    }
    if (mobs->second > 0.4) {
        mobs->rect.left += 33;
        sfClock_restart(mobs->clock);
    }
}

void    move_left_mob(t_mob *mobs)
{
    mobs->timer = sfClock_getElapsedTime(mobs->clock);
    mobs->second = mobs->timer.microseconds / 1000000.0;
    if (mobs->rect.top != 32 || mobs->rect.left >= 261) {
        mobs->rect.top = 32;
        mobs->rect.left = 196;
    }
    if (mobs->second > 0.4) {
        mobs->rect.left += 33;
        sfClock_restart(mobs->clock);
    }
}

void    move_right_mob(t_mob *mobs)
{
    mobs->timer = sfClock_getElapsedTime(mobs->clock);
    mobs->second = mobs->timer.microseconds / 1000000.0;
    if (mobs->rect.top != 66 || mobs->rect.left >= 261) {
        mobs->rect.top = 66;
        mobs->rect.left = 196;
    }
    if (mobs->second > 0.4) {
        mobs->rect.left += 33;
        sfClock_restart(mobs->clock);
    }
}

void    mob1_rect(t_list_mob *allmob)
{
    t_mob *mobs = allmob->first;
    sfFloatRect box;

    while (mobs != NULL) {
        if (mobs->orientation == SOUTH) {
            move_down_mob(mobs);
            sfSprite_setTextureRect(mobs->mobs, mobs->rect);
        }
        else if (mobs->orientation == NORTH) {
            move_up_mob(mobs);
            sfSprite_setTextureRect(mobs->mobs, mobs->rect);
        }
        else if (mobs->orientation == WEST) {
            move_left_mob(mobs);
            sfSprite_setTextureRect(mobs->mobs, mobs->rect);
        }
        else if (mobs->orientation == EST) {
            move_right_mob(mobs);
            sfSprite_setTextureRect(mobs->mobs, mobs->rect);
        }
		mobs = mobs->next;
    }
    return;
}