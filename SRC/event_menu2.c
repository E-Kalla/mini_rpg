/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** event_menu2
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

int     on_play(sfMouseMoveEvent move, t_menu *menu)
{
    if (move.x >= menu->vplay.x && move.x <= menu->vplay.x + 300
        && move.y >= menu->vplay.y && move.y <= menu->vplay.y + 300)
        return (1);
    return (0);
}

int     on_exit_but(sfMouseMoveEvent move, t_menu *menu)
{
    if (move.x >= menu->vexit.x && move.x <= menu->vexit.x + 300
        && move.y >= menu->vexit.y && move.y <= menu->vexit.y + 300)
        return (1);
    return (0);
}

int     on_opt(sfMouseMoveEvent move, t_menu *menu)
{
    if (move.x >= menu->vopt.x && move.x <= menu->vopt.x + 300
        && move.y >= menu->vopt.y && move.y <= menu->vopt.y + 300)
        return (1);
    return (0);
}

void    reset_menu_button(sfMouseMoveEvent move, t_menu *menu)
{
    if ((on_exit_but(move, menu) == 0) && (on_opt(move, menu) == 0) &&
        on_play(move, menu) == 0) {
    sfSprite_setTexture(menu->playbuttons, menu->playbutton, sfTrue);
    sfSprite_setTexture(menu->settingbuttons, menu->settingbutton, sfTrue);
    sfSprite_setTexture(menu->exitbuttons, menu->exitbutton, sfTrue);
    }
}

void    event_menu_moved(sfMouseMoveEvent move, t_menu *menu)
{
    sfVector2f spot;
    spot.x = move.x;
    spot.y = move.y;
    sfSprite_setPosition(menu->cursors, spot);
    if (on_play(move, menu))
        sfSprite_setTexture(menu->playbuttons, menu->onplay, sfTrue);
    if (on_opt(move, menu))
        sfSprite_setTexture(menu->settingbuttons, menu->onsetting, sfTrue);
    if (on_exit_but(move, menu))
        sfSprite_setTexture(menu->exitbuttons, menu->onexit, sfTrue);
    reset_menu_button(move,menu);
}