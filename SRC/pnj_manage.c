/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** pnj manage
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    move_pnj_manage2(t_list_pnj *npc, t_pnj *pnj)
{
    pnj->mov.x = 1;
    pnj->mov.y = 0;
    pnj->orientation = EST;
    sfSprite_move(pnj->pnjs, pnj->mov);
    sfSprite_move(pnj->stats, pnj->mov);
}

void    move_pnj_manage(t_list_pnj *npc, t_pnj *pnj)
{
    pnj->mov.x = -1;
    pnj->mov.y = 0;
    pnj->orientation = WEST;
    sfSprite_move(pnj->pnjs, pnj->mov);
    sfSprite_move(pnj->stats, pnj->mov);
}

void    pnj1_movement(t_list_pnj *npc)
{
    t_pnj *pnj = npc->first;
    sfFloatRect box;

    while (pnj != NULL) {
        box = sfSprite_getGlobalBounds(pnj->pnjs);
        if (pnj->step == 0) {
            if (box.left < 716 && pnj->step == 0) {
                move_pnj_manage2(npc, pnj);
            } else
                pnj->step = 1;
        }
        if (pnj->step == 1) {
            if (box.left > 600 && pnj->step == 1) {
                move_pnj_manage(npc, pnj);
            } else
                pnj->step = 0;
        }
        pnj = pnj->next;
    }
}

void    pnj_manager(t_game *game)
{
    pnj1_movement(game->npc);
}