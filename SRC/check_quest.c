/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_quest
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

int     die_mob(t_list_mob *allmob)
{
    int nb = 0;
    t_mob *mob = allmob->first;

    while (mob != NULL) {
        if (mob->alive == false)
            nb += 1;
        mob = mob->next;
    }
    return (nb);
}

bool    check_quest_one(t_game *games)
{
    sfFloatRect player = sfSprite_getGlobalBounds(games->character->players);
    sfFloatRect pnj = sfSprite_getGlobalBounds(games->npc->first->pnjs);
    if (player.left >= pnj.left - 10 && 
    player.left + player.width <= pnj.left + pnj.width + 10 &&
    player.top >= pnj.top &&
    player.top + player.height <= pnj.top  + pnj.height + 20) {
        games->quest->statfirst = COMPLETE;
        games->quest->statsecond = CURRENT;
        games->quest->obj = die_mob(games->allmob);
        return (true);
    }
    return (false);
}

bool    check_quest_two(t_game *games)
{
    if (die_mob(games->allmob) >= games->quest->obj + 10)
        return (true);
    return (false);
}

bool    check_quest_three(t_game *games)
{
    return (false);
}