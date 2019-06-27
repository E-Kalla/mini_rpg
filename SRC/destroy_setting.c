/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** destroy setting
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    destroy_setting(t_setting *setting)
{
    sfSprite_destroy(setting->green);
    sfSprite_destroy(setting->red);
    sfSprite_destroy(setting->blue);
    sfTexture_destroy(setting->sett);
}