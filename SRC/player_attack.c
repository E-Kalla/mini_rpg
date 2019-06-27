/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** player attack
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    basic_attack_down(t_player *character, t_game *game)
{
    if (character->attack == 0)
        sfClock_restart(character->clock);
    if (character->attack == 1) {
        character->timer = sfClock_getElapsedTime(character->clock);
        character->second = character->timer.microseconds / 100000.0;
        character->rectp.width = 24;
        character->rectp.top = 282;
        character->rectp.left = 540;
        character->rectp.height = 26;
        sfSprite_setTextureRect(character->players, character->rectp);
        if (character->second > 0.4 && character->second < 1) {
            character->rectp.width = 22;
            character->rectp.top = 282;
            character->rectp.left = 570;
            character->rectp.height = 32;
            sfSprite_setTextureRect(character->players, character->rectp);
        }
        if (character->second >= 1) {
            character->rectp.width = 22;
            character->rectp.top = 282;
            character->rectp.left = 596;
            character->rectp.height = 32;
            sfSprite_setTextureRect(character->players, character->rectp);
            character->attack = 0;
        }
    }
}

void    basic_attack_up(t_player *character, t_game *game)
{
    if (character->attack == 0)
        sfClock_restart(character->clock);
    if (character->attack == 1) {
        character->timer = sfClock_getElapsedTime(character->clock);
        character->second = character->timer.microseconds / 100000.0;
        character->rectp.width = 24;
        character->rectp.top = 242;
        character->rectp.left = 516;
        character->rectp.height = 24;
        sfSprite_setTextureRect(character->players, character->rectp);
        if (character->second > 0.4 && character->second < 1) {
            character->rectp.width = 24;
            character->rectp.top = 234;
            character->rectp.left = 545;
            character->rectp.height = 32;
            sfSprite_setTextureRect(character->players, character->rectp);
        }
        if (character->second >= 1) {
            character->rectp.width = 24;
            character->rectp.top = 228;
            character->rectp.left = 580;
            character->rectp.height = 38;
            sfSprite_setTextureRect(character->players, character->rectp);
            character->attack = 0;
        }
    }
}

void    basic_attack_right(t_player *character, t_game *game)
{
    if (character->attack == 0)
        sfClock_restart(character->clock);
    if (character->attack == 1) {
        character->timer = sfClock_getElapsedTime(character->clock);
        character->second = character->timer.microseconds / 100000.0;
        character->rectp.width = 26;
        character->rectp.top = 190;
        character->rectp.left = 828;
        character->rectp.height = 26;
        sfSprite_setTextureRect(character->players, character->rectp);
        if (character->second > 0.4 && character->second < 1) {
            character->rectp.width = 32;
            character->rectp.top = 194;
            character->rectp.left = 794;
            character->rectp.height = 22;
            sfSprite_setTextureRect(character->players, character->rectp);
        }
        if (character->second >= 1) {
            character->rectp.width = 33;
            character->rectp.top = 194;
            character->rectp.left = 756;
            character->rectp.height = 22;
            sfSprite_setTextureRect(character->players, character->rectp);
            character->attack = 0;
        }
    }
}

void    basic_attack_left(t_player *character, t_game *game)
{
    if (character->attack == 0)
        sfClock_restart(character->clock);
    if (character->attack == 1) {
        game->character->timer = sfClock_getElapsedTime(character->clock);
        game->character->second = character->timer.microseconds / 100000.0;
        game->character->rectp.width = 26;
        game->character->rectp.top = 189;
        game->character->rectp.left = 544;
        game->character->rectp.height = 27;
        sfSprite_setTextureRect(character->players, character->rectp);
        if (game->character->second > 1) {
            game->character->rectp.width = 32;
            game->character->rectp.top = 194;
            game->character->rectp.left = 610;
            game->character->rectp.height = 20;
            sfSprite_setTextureRect(character->players, character->rectp);
            character->attack = 0;
        }
    }
}