/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fill_list
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

t_list_wall  *add_wall(t_list_wall *list, t_paramwall *opt)
{
    t_wall *new = malloc(sizeof(*new));

    new->pos = opt->pos;
    new->size = opt->size;
    new->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(new->rect, new->pos);
    sfRectangleShape_setSize(new->rect, new->size);
    new->next = NULL;
    if (list->first == NULL) {
        new->prev = NULL;
        list->last = new;
        list->first = new;
    } else {
        list->last->next = new;
        new->prev = list->last;
        list->last = new;
    }
    list->nb += 1;
    return (list);
}

void    param_mob(t_parammob *new, t_mob *mob, sfVector2f tmp) 
{
    mob->clock = sfClock_create();
    mob->mobs = sfSprite_create();
    mob->mob = sfTexture_createFromFile("IMG/pnj2.png", NULL);
    mob->life = sfTexture_createFromFile("IMG/hpmob.png", NULL);
    mob->lifes = sfSprite_create();
    mob->stats = sfSprite_create();
    mob->stat = sfTexture_createFromFile("IMG/danger.png", NULL);
    sfSprite_setTexture(mob->stats, mob->stat, sfTrue);
    sfSprite_setTexture(mob->mobs, mob->mob, sfTrue);
    sfSprite_setTexture(mob->lifes, mob->life, sfTrue);
    sfSprite_setTextureRect(mob->mobs, mob->rect);
    sfSprite_setPosition(mob->stats, mob->vstat);
    sfSprite_setPosition(mob->lifes, tmp);
    sfSprite_setTextureRect(mob->lifes, mob->reclife);
    sfSprite_setPosition(mob->mobs, mob->pos);
}

void    get_mob(t_parammob *new, t_mob *mob)
{
    sfVector2f tmp = new->pos;
    tmp.y -= 3;
    tmp.x -= 5;
    mob->alive = new->alive;
    mob->pos = new->pos;
    mob->rect = new->rect;
    mob->hp = new->hp;
    mob->step = new->step;
    mob->strenght = new->strenght;
    mob->strenght = new->smart;
    mob->strenght = new->agility;
    mob->strenght = new->mana ;
    mob->mov = new->mov;
    mob->reclife = new->reclife;
    mob->vstat = tmp;
    mob->vstat.y -= 16;
    mob->vstat.x += 6;
    param_mob(new, mob, tmp);
    mob->scream = sfMusic_createFromFile("SOUND/hitmonster.ogg");
}

t_list_mob  *add_mob(t_list_mob *list, t_parammob *mob)
{
    t_mob *new = malloc(sizeof(*new));

    get_mob(mob, new);
    new->next = NULL;
    if (list->first == NULL) {
        new->prev = NULL;
        list->last = new;
        list->first = new;
    } else {
        list->last->next = new;
        new->prev = list->last;
        list->last = new;
    }
    list->nb += 1;
    return (list);
}