/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** view
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    view_manager(t_game *game)
{
    sfVector2f tmp;

    game->quest->rquest = sfView_getCenter(game->view);
    sfFloatRect pos = sfSprite_getGlobalBounds(game->character->players);
    tmp.x = pos.left - 100;
    tmp.y = pos.top - 100;
    game->quest->rquest.x -= 200;
    game->quest->rquest.y -= 150;
    sfSprite_setPosition(game->pauses, tmp);
    sfSprite_setPosition(game->quest->quests, game->quest->rquest);
}