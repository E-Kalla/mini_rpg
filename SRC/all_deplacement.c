/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** deplacement
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    player_animation(t_player *character, t_game *game)
{
    if (character->orientation == WEST)
        basic_attack_left(character, game);
    if (character->orientation == EST)
        basic_attack_right(character, game);
    if (character->orientation == NORTH)
        basic_attack_up(character, game);
    if (character->orientation == SOUTH)
        basic_attack_down(character, game);
}

void    all_animation_manager(t_game *game)
{
    player_animation(game->character, game);
}