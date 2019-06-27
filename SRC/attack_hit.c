/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    hit_up(t_list_mob *allmob, sfFloatRect sword)
{
    t_mob *mob = allmob->first;
    sfFloatRect box;

    sword.top -= 10;
    sword.left += sword.width/2;
    while (mob != NULL) {
        box = sfSprite_getGlobalBounds(mob->mobs);
        if (sword.top <= (box.top + box.height) && sword.top >= box.top &&
        sword.left <= (box.left + box.width + 10) &&
        sword.left >= box.left - 10 && mob->alive == true) {
            mob->hp -= 50;
            mob->reclife.top = 17;
            sfSprite_setTextureRect(mob->lifes, mob->reclife);
            sfMusic_play(mob->scream);
        }
        mob = mob->next;
    }
}

void    hit_down(t_list_mob *allmob, sfFloatRect sword)
{
    t_mob *mob = allmob->first;
    sfFloatRect box;

    sword.top += 10;
    sword.top += sword.height;
    sword.left += sword.width/2;
    while (mob != NULL) {
        box = sfSprite_getGlobalBounds(mob->mobs);
        if (sword.top >= box.top && sword.top <= box.top + box.height &&
        sword.left <= (box.left + box.width + 10) &&
        sword.left >= box.left - 10 && mob->alive == true) {
            mob->hp -= 50;
            mob->reclife.top = 17;
            sfSprite_setTextureRect(mob->lifes, mob->reclife);
            sfMusic_play(mob->scream);
        }
        mob = mob->next;
    }
}

void    hit_right(t_list_mob *allmob, sfFloatRect sword)
{
    t_mob *mob = allmob->first;
    sfFloatRect box;

    sword.left += 5;
    sword.left += sword.width;
    sword.top += sword.height/2;
    while (mob != NULL) {
        box = sfSprite_getGlobalBounds(mob->mobs);
        if (sword.left >= box.left && sword.left <= (box.left + box.width)
        && sword.top >= box.top - 10 &&
        sword.top <= box.top + box.height + 10 && mob->alive == true) {
            mob->hp -= 50;
            mob->reclife.top = 17;
            sfSprite_setTextureRect(mob->lifes, mob->reclife);
            sfMusic_play(mob->scream);
        }
        mob = mob->next;
    }
}

void    hit_left(t_list_mob *allmob, sfFloatRect sword)
{
    t_mob *mob = allmob->first;
    sfFloatRect box;

    sword.left -= 5;
    sword.top += sword.height/2;
    while (mob != NULL) {
        box = sfSprite_getGlobalBounds(mob->mobs);
        if (sword.left <= (box.left + box.width) && sword.left >= box.left &&
        sword.top >= box.top - 10 &&
        sword.top + sword.height <= box.top + box.height + 10 && 
        mob->alive == true) {
            mob->hp -= 50;
            mob->reclife.top = 17;
            sfSprite_setTextureRect(mob->lifes, mob->reclife);
            sfMusic_play(mob->scream);
        }
        mob = mob->next;
    }
}

void    attack_hit(t_game *game)
{
    sfFloatRect sword;

    sword = sfSprite_getGlobalBounds(game->character->players);
    if (game->character->orientation == NORTH) {
        hit_up(game->allmob, sword);
    }
    if (game->character->orientation == WEST) {
        hit_left(game->allmob, sword);
    }
    if (game->character->orientation == EST) {
        hit_right(game->allmob, sword);
    }
    if (game->character->orientation == SOUTH) {
        hit_down(game->allmob, sword);
    }
}