/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** destroypnj
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    destroy_pnj(t_list_pnj *npc)
{
    t_pnj *pnj = npc->first;
    t_pnj *tmp;

    while (pnj!= NULL) {
        tmp = pnj->next;
        sfClock_destroy(pnj->clock);
        sfSprite_destroy(pnj->pnjs);
        sfTexture_destroy(pnj->pnj);
        sfSprite_destroy(pnj->stats);
        sfTexture_destroy(pnj->stat);
        free(pnj);
        pnj = tmp;
    }
}