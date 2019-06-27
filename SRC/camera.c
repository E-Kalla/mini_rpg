/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** can move camera
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

bool    can_up_camera(t_game *game)
{
    sfVector2f center;
    sfVector2f perso;

    perso = sfSprite_getPosition(game->character->players);
    perso.x += game->character->rectp.width / 2;
    perso.y += game->character->rectp.height / 2;
    center = sfView_getCenter(game->view);
    if ((center.y - (3.1 + (game->viewsize.y /2)) < 1530) ||
        (perso.y > center.y))
        return (false);
    return (true);
}

bool    can_down_camera(t_game *game)
{
    sfVector2f center;
    sfVector2f perso;

    perso = sfSprite_getPosition(game->character->players);
    perso.x += game->character->rectp.width / 2;
    perso.y += game->character->rectp.height / 2;
    center = sfView_getCenter(game->view);
    if ((center.y + (3.1 + (game->viewsize.y /2)) > 2550) ||
        (perso.y < center.y))
        return (false);
    return (true);
}

bool    can_right_camera(t_game *game)
{
    sfVector2f center;
    sfVector2f perso;

    perso = sfSprite_getPosition(game->character->players);
    perso.x += game->character->rectp.width / 2;
    perso.y += game->character->rectp.height / 2;
    center = sfView_getCenter(game->view);
    if ((center.x + (3.1 + (game->viewsize.x /2)) > 971) ||
        (perso.x < center.x))
        return (false);
    return (true);
}

bool    can_left_camera(t_game *game)
{
    sfVector2f center;
    sfVector2f perso;

    perso = sfSprite_getPosition(game->character->players);
    perso.x += game->character->rectp.width / 2;
    perso.y += game->character->rectp.height / 2;
    center = sfView_getCenter(game->view);
    if ((center.x - (3.1 + (game->viewsize.x /2)) < 0) || (perso.x > center.x))
        return (false);
    return (true);
}