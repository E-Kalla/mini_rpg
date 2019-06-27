/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** event keygame
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void rect_pause(t_game *game)
{
    if (game->pausestatut == RESUME) {
        game->rpause.top = 21;
        game->rpause.left = 176;
        game->rpause.width = 220;
        game->rpause.height = 187;
        sfSprite_setTextureRect(game->pauses, game->rpause);
    } else {
        game->rpause.top = 222;
        game->rpause.left = 179;
        game->rpause.width = 220;
        game->rpause.height = 187;
        sfSprite_setTextureRect(game->pauses, game->rpause);
    }
}

void    event_keygame3(sfKeyEvent key, t_game *game)
{
    if (key.code == sfKeySpace && game->speed != 4)
        game->speed = 4;
    else if (key.code == sfKeySpace && game->speed == 4)
        game->speed = 0;
    if (key.code == sfKeyQ && game->scene != QUEST)
        game->scene = QUEST;
    else if (key.code == sfKeyQ && game->scene == QUEST)
        game->scene = MAP;
    else if (key.code == sfKeyReturn && game->scene == PAUSE &&
    game->pausestatut == RESUME) {
        game->scene = MAP;
        sfMusic_play(game->music);
    }
}

void    event_keygame2(sfKeyEvent key, t_game *game)
{
    t_menu menu;

    if (key.code == sfKeyA) {
        game->character->attack = 1;
        attack_hit(game);
    }
    else if (key.code == sfKeyUp && game->scene == PAUSE) {
        game->pausestatut = RESUME;
    }
    else if (key.code == sfKeyDown && game->scene == PAUSE) {
        game->pausestatut = EXIT;
    }
    else if (key.code == sfKeyReturn && game->scene == PAUSE &&
    game->pausestatut == EXIT) {
        sfRenderWindow_close(game->gamewindow);
        initialise_menu(&menu);
        start_menu(&menu);
    }
    rect_pause(game);
    event_keygame3(key, game);
}

void    event_keygame(sfKeyEvent key, t_game *game)
{
    if (key.code == 36 && game->scene != PAUSE) {
        game->scene = PAUSE;
        sfMusic_pause(game->music);
    }
    else if (key.code == sfKeyLeft && game->scene != PAUSE) {
        move_left(game);
    }
    else if (key.code == sfKeyRight && game->scene != PAUSE) {
        move_right(game);
    }
    else if (key.code == sfKeyUp && game->scene != PAUSE) {
        move_up(game);
    }
    else if (key.code == sfKeyDown && game->scene != PAUSE) {
        move_down(game);
    }
    else if (key.code == 36 && game->scene == PAUSE) {
        game->scene = MAP;
        sfMusic_play(game->music);
    }
    event_keygame2(key, game);
}