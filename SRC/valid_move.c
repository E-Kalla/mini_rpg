/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** valid_move
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

bool valid_left_move(sfFloatRect box, t_list_wall *allwall, float speed)
{
    t_wall *wall = allwall->first;

    while (wall != NULL) {
        if (box.left - speed <= wall->pos.x + wall->size.x &&
        box.left + box.width > wall->pos.x + wall->size.x &&
        box.top + box.height >= wall->pos.y && box.top + box.height
        <= wall->pos.y + wall->size.y)
			return (false);
		wall = wall->next;
    }
    return (true);
}

bool valid_right_move(sfFloatRect box, t_list_wall *allwall, float speed)
{
    t_wall *wall = allwall->first;

    while (wall != NULL) {
        if (box.left + speed + box.width >= wall->pos.x &&
        box.left < wall->pos.x &&
        box.top + box.height >= wall->pos.y && box.top + box.height
        <= wall->pos.y + wall->size.y)
            return (false);
        wall = wall->next;
    }
    return (true);
}

bool valid_down_move(sfFloatRect box, t_list_wall *allwall, float speed)
{
    t_wall *wall = allwall->first;

    while (wall != NULL) {
        if ((box.top + speed + box.height >= wall->pos.y)
        && box.top < wall ->pos.y &&
        box.left >= wall->pos.x && box.left + box.width
        <= wall->pos.x + wall->size.x)
            return (false);
        wall = wall->next;
    }
    return (true);
}

bool valid_up_move(sfFloatRect box, t_list_wall *allwall, float speed)
{
    t_wall *wall = allwall->first;

    while (wall != NULL) {
        if ((box.top - speed <= wall->pos.y + wall->size.y)
        && box.top + box.height > wall ->pos.y + wall->size.y &&
        box.left >= wall->pos.x && box.left + box.width
        <= wall->pos.x + wall->size.x)
            return (false);
        wall = wall->next;
    }
    return (true);
}