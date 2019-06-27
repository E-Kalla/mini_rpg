/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** destroy quest
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    destroy_quest(t_quest *quest)
{
    sfTexture_destroy(quest->quest);
    sfSprite_destroy(quest->quests);
}