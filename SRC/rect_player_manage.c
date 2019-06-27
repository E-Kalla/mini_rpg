/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** move rect
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    move_right_rect(t_player *character)
{
    character->rectp.height = 25;
    character->rectp.width = 20;
    if (character->rectp.left > 106)
        character->rectp.left = 2;
    if (character->rectp.top != 54) {
        character->rectp.top = 54;
        character->rectp.left = 2;
    }
    if (character->rectp.left == 54) {
        character->rectp.left += 28;
        return;
    }
    if (character->rectp.left == 82) {
        character->rectp.left += 24;
        return;
    }
    if (character->rectp.left <= 106) {
        character->rectp.left += 26;
    }
}

void    move_left_rect(t_player *character)
{
    character->rectp.height = 25;
    character->rectp.width = 18;
    if (character->rectp.left < 23)
        character->rectp.left = 138;
    if (character->rectp.top != 350) {
        character->rectp.top = 350;
        character->rectp.left = 138;
    }
    if (character->rectp.left >= 23) {
        character->rectp.left -= 26;
    }
}

void    move_up_rect2(t_player *character)
{
    if (character->rectp.left == 178) {
        character->rectp.left += 24;
        character->rectp.width = 20;
        return;
    }
    if (character->rectp.left <= 202) {
        character->rectp.left += 22;
    }
}

void    move_up_rect(t_player *character)
{
    character->rectp.height = 25;
    character->rectp.width = 20;
    if (character->rectp.left >= 202)
        character->rectp.left = 106;
    if (character->rectp.top != 94) {
        character->rectp.top = 94;
        character->rectp.left = 106;
    }
    if (character->rectp.left == 128) {
        character->rectp.left += 26;
        character->rectp.width = 22;
        return;
    }
    if (character->rectp.left == 154) {
        character->rectp.left += 24;
        character->rectp.width = 20;
        return;
    }
    move_up_rect2(character);
}

void    move_down_rect(t_player *character)
{
    character->rectp.height = 25;
    character->rectp.width = 20;
    if (character->rectp.left > 200)
        character->rectp.left = 120;
    if (character->rectp.top != 10) {
        character->rectp.top = 10;
        character->rectp.left = 120;
    }
    if (character->rectp.left == 172) {
        character->rectp.left += 22;
        return;
    }
    if (character->rectp.left <= 196) {
        character->rectp.left += 26;
    }
}