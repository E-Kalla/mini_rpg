/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** event_game_move
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    event_game_moved(sfMouseMoveEvent move, t_game *game)
{
    sfVector2f spot;
    spot.x = move.x;
    spot.y = move.y;
    sfSprite_setPosition(game->cursors, spot);
}