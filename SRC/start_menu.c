/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** start_menu
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    key_menu(sfKeyEvent key, t_menu *menu)
{
    if (key.code == 36)
        menu->scene = MENU;
}

int    event_menu_manager(t_menu *menu)
{
    while (sfRenderWindow_pollEvent(menu->menuwindow, &menu->event)) {
        if (menu->event.type == sfEvtClosed)
            sfRenderWindow_close(menu->menuwindow);
        if (menu->event.type == sfEvtMouseButtonPressed && menu->scene
            != SETTING)
            event_click(menu->event.mouseButton, menu);
        if (menu->event.type == sfEvtMouseMoved)
            event_menu_moved(menu->event.mouseMove,menu);
        if (menu->event.type == sfEvtKeyPressed)
            key_menu(menu->event.key, menu);
        if (menu->event.type == sfEvtMouseButtonPressed && menu->scene
            == SETTING)
            setting_event(menu->event.mouseButton, menu);
    }
    return (0);
}

void    draw_menu(t_menu *menu)
{
    sfRenderWindow_drawSprite(menu->menuwindow, menu->backs, NULL);
    sfRenderWindow_drawSprite(menu->menuwindow, menu->settingbuttons, NULL);
    sfRenderWindow_drawSprite(menu->menuwindow, menu->playbuttons, NULL);
    sfRenderWindow_drawSprite(menu->menuwindow, menu->exitbuttons, NULL);
    if (menu->scene == SETTING) {
        sfRenderWindow_drawSprite(menu->menuwindow, menu->settings, NULL);
        sfRenderWindow_drawSprite(menu->menuwindow, menu->opt->green, NULL);
        sfRenderWindow_drawSprite(menu->menuwindow, menu->opt->red, NULL);
        sfRenderWindow_drawSprite(menu->menuwindow, menu->opt->blue, NULL);
    }
    sfRenderWindow_drawSprite(menu->menuwindow, menu->cursors, NULL);
}

int     start_menu(t_menu *menu)
{
    sfRenderWindow_setMouseCursorVisible(menu->menuwindow, sfFalse);
    sfMusic_play(menu->music);
    while (sfRenderWindow_isOpen(menu->menuwindow)) {
        sfRenderWindow_clear(menu->menuwindow, sfBlack);
        draw_menu(menu);
        event_menu_manager(menu);
        sfRenderWindow_display(menu->menuwindow);
    }
    destroy_menu(menu);
    return (0);
}