/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** quest
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    quest_core(t_game *games)
{
    if (games->quest->statfirst == CURRENT)
        if (check_quest_one(games) == true) {
            games->quest->which.top = 128;
            sfSprite_setTextureRect(games->quest->quests, 
            games->quest->which);
        }
    if (games->quest->statsecond == CURRENT)
        if (check_quest_two(games) == true) {
            games->quest->which.top = 8;
            sfSprite_setTextureRect(games->quest->quests,
            games->quest->which);
        }
    if (games->quest->statthird == CURRENT)
        check_quest_three(games);
}

void    init_quest(t_game *games)
{
    games->quest = malloc(sizeof(t_quest));
    games->quest->quest = sfTexture_createFromFile("IMG/fon.png", NULL);
    games->quest->quests = sfSprite_create();
    games->quest->statfirst = CURRENT;
    games->quest->statsecond = NOT;
    games->quest->statthird = NOT;
    games->quest->which.left = 16;
    games->quest->which.top = 249;
    games->quest->which.width = 389;
    games->quest->which.height = 108;
    sfSprite_setTexture(games->quest->quests, games->quest->quest, sfTrue);
    sfSprite_setTextureRect(games->quest->quests, games->quest->which);
}