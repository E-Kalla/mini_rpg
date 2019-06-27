/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** event_menu
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

int     is_on_play(sfMouseButtonEvent mouseButton, t_menu *menu)
{
    if (mouseButton.x >= menu->vplay.x && mouseButton.x <= menu->vplay.x + 300
        && mouseButton.y >= menu->vplay.y &&
        mouseButton.y <= menu->vplay.y + 300)
        return (1);
    return (0);
}

int     is_on_exit_but(sfMouseButtonEvent mouseButton, t_menu *menu)
{
    if (mouseButton.x >= menu->vexit.x && mouseButton.x <= menu->vexit.x + 300
        && mouseButton.y >= menu->vexit.y &&
        mouseButton.y <= menu->vexit.y + 300)
        return (1);
    return (0);
}

int     is_on_opt(sfMouseButtonEvent mouseButton, t_menu *menu)
{
    if (mouseButton.x >= menu->vopt.x && mouseButton.x <= menu->vopt.x + 300
        && mouseButton.y >= menu->vopt.y &&
        mouseButton.y <= menu->vopt.y + 300)
        return (1);
    return (0);
}

void    reset_menu_button_click(sfMouseButtonEvent mouseButton, t_menu *menu)
{
    if ((is_on_exit_but(mouseButton, menu) == 0) &&
        (is_on_opt(mouseButton, menu) == 0) &&
        is_on_play(mouseButton, menu) == 0) {
    sfSprite_setTexture(menu->playbuttons, menu->playbutton, sfTrue);
    sfSprite_setTexture(menu->settingbuttons, menu->settingbutton, sfTrue);
    sfSprite_setTexture(menu->exitbuttons, menu->exitbutton, sfTrue);
    }
}

int    event_click(sfMouseButtonEvent mouseButton, t_menu *menu)
{
    t_game game;

    sfMusic_play(menu->click);
    if (is_on_play(mouseButton, menu)) {
        sfMusic_stop(menu->music);
        sfSprite_setTexture(menu->playbuttons, menu->playclick, sfTrue);
        sfRenderWindow_close(menu->menuwindow);
        init_game(&game, menu);
        start_game(&game);
    }
    if (is_on_opt(mouseButton, menu)) {
        menu->scene = SETTING;
        sfSprite_setTexture(menu->settingbuttons, menu->settingclick, sfTrue);
    }
    if (is_on_exit_but(mouseButton, menu)) {
        sfSprite_setTexture(menu->exitbuttons, menu->exitclick, sfTrue);
        sfRenderWindow_close(menu->menuwindow);
    }
    reset_menu_button_click(mouseButton, menu);
    return (0);
}