/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** movement
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    move_left(t_game *game)
{
    sfVector2f move;
    sfFloatRect box = sfSprite_getGlobalBounds(game->character->players);

    if (valid_left_move(box,game->allwall,3.1) == true) {
        game->character->moving = true;
        move.x = -3.1 - game->speed;
        move.y = 0;
        if (can_left_camera(game) == true) {
            game->viewcenter.x -= 3.1 - game->speed;
            sfView_move(game->view, move);
        }
        sfSprite_move(game->character->players, move);
    }
    game->character->orientation = WEST;
    move_left_rect(game->character);
    sfSprite_setTextureRect(game->character->players, game->character->rectp);
    game->character->moving = false;
}

void    move_right(t_game *game)
{
    sfVector2f move;
    sfFloatRect box = sfSprite_getGlobalBounds(game->character->players);

    if (valid_right_move(box,game->allwall,3.1) == true) {
        game->character->moving = true;
        move.x = 3.1 + game->speed;
        move.y = 0;
        if (can_right_camera(game) == true) {
            game->viewcenter.x += 3.1 + game->speed;
            sfView_move(game->view, move);
        }
        sfSprite_move(game->character->players, move);
    }
    game->character->orientation = EST;
    move_right_rect(game->character);
    sfSprite_setTextureRect(game->character->players, game->character->rectp);
    game->character->moving = false;
}

void    move_up(t_game *game)
{
    sfVector2f move;
    sfFloatRect box = sfSprite_getGlobalBounds(game->character->players);

    if (valid_up_move(box,game->allwall,3.1) == true) {
        game->character->moving = true;
        move.x = 0;
        move.y = -3.1 - game->speed;
        if (can_up_camera(game) == true) {
            game->viewcenter.y -= 3.1 - game->speed;
            sfView_move(game->view, move);
        }
        sfSprite_move(game->character->players, move);
    }
    game->character->orientation = NORTH;
    move_up_rect(game->character);
    sfSprite_setTextureRect(game->character->players, game->character->rectp);
    game->character->moving = false;
}

void    move_down(t_game *game)
{
    sfVector2f move;
    sfFloatRect box = sfSprite_getGlobalBounds(game->character->players);

    if (valid_down_move(box,game->allwall,3.1) == true) {
        game->character->moving = true;
        move.x = 0;
        move.y = 3.1 + game->speed;
        if (can_down_camera(game) == true) {
            game->viewcenter.y += 3.1 + game->speed;
            sfView_move(game->view, move);
        }
        sfSprite_move(game->character->players, move);
    }
    game->character->orientation = SOUTH;
    move_down_rect(game->character);
    sfSprite_setTextureRect(game->character->players, game->character->rectp);
    game->character->moving = false;
}