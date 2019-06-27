/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** destroy menu
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    destroy_menu2(t_menu *menu)
{
    sfMusic_destroy(menu->music);
    sfMusic_destroy(menu->click);
    sfSprite_destroy(menu->cursors);
    sfTexture_destroy(menu->cursor);
    sfSprite_destroy(menu->settings);
    sfTexture_destroy(menu->setting);
    destroy_setting(menu->opt);
}

void    destroy_menu(t_menu *menu)
{
    sfRenderWindow_destroy(menu->menuwindow);
    sfTexture_destroy(menu->back);
    sfTexture_destroy(menu->settingbutton);
    sfTexture_destroy(menu->playbutton);
    sfTexture_destroy(menu->exitbutton);
    sfTexture_destroy(menu->onexit);
    sfTexture_destroy(menu->onplay);
    sfTexture_destroy(menu->onsetting);
    sfTexture_destroy(menu->playclick);
    sfTexture_destroy(menu->settingclick);
    sfTexture_destroy(menu->exitclick);
    sfSprite_destroy(menu->backs);
    sfSprite_destroy(menu->settingbuttons);
    sfSprite_destroy(menu->playbuttons);
    sfSprite_destroy(menu->exitbuttons);
    destroy_menu2(menu);
}