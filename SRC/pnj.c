/*
** EPITECH PROJECT, 2019
** my rpg
** File description:
** pnj
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    draw_pnj(t_list_pnj *npc, t_game *game)
{
    t_pnj *new = npc->first;

    while (new != NULL) {
            sfRenderWindow_drawSprite(game->gamewindow, new->pnjs, NULL);
            if (game->quest->statfirst == CURRENT)
                sfRenderWindow_drawSprite(game->gamewindow, new->stats, NULL);
        new = new->next;
    }
}

void    get_pnj(t_pnj *pnj)
{
    pnj->pos.x = 602;
    pnj->pos.y = 2228;
    pnj->rect.top = 0;
    pnj->rect.left = 196;
    pnj->rect.width = 24;
    pnj->rect.height = 34;
    pnj->step = 0;
    pnj->vstats.x = 607;
    pnj->vstats.y = 2210;
    pnj->clock = sfClock_create();
    pnj->stats = sfSprite_create();
    pnj->stat = sfTexture_createFromFile("IMG/danger.png", NULL);
    sfSprite_setTexture(pnj->stats, pnj->stat, sfTrue);
    pnj->pnjs = sfSprite_create();
    pnj->pnj = sfTexture_createFromFile("IMG/png1.png", NULL);
    sfSprite_setTexture(pnj->pnjs, pnj->pnj, sfTrue);
    sfSprite_setTextureRect(pnj->pnjs, pnj->rect);
    sfSprite_setPosition(pnj->pnjs, pnj->pos);
    sfSprite_setPosition(pnj->stats, pnj->vstats);
}

t_list_pnj *addpnj(t_list_pnj *npc)
{
    t_pnj *new = malloc(sizeof(*new));

    get_pnj(new);
    new->next = NULL;
    if (npc->first == NULL) {
        new->prev = NULL;
        npc->last = new;
        npc->first = new;
    } else {
        npc->last->next = new;
        new->prev = npc->last;
        npc->last = new;
    }
    npc->nb += 1;
    return (npc);
}