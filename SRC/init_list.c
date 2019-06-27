/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_list
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

t_list_wall *init_list_wall(void)
{
    t_list_wall *new = malloc(sizeof(*new));

    new->nb = 0;
    new->first = NULL;
    new->last = NULL;
    return (new);
}

t_list_pnj *init_npc(void)
{
    t_list_pnj *new = malloc(sizeof(*new));

    new->nb = 0;
    new->first = NULL;
    new->last = NULL;
    return (new);
}

t_list_mob *init_list_mob(void)
{
    t_list_mob *new = malloc(sizeof(*new));

    new->nb = 0;
    new->first = NULL;
    new->last = NULL;
    return (new);
}