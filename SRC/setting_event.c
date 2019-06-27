/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** setting event
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

int     is_on_green(sfMouseButtonEvent mouseButton, t_setting *sett)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(sett->green);
    if (mouseButton.x >= 930 && mouseButton.x <= 985
        && mouseButton.y >= 500 && mouseButton.y <= 538)
        return (1);
    return (0);
}

int     is_on_blue(sfMouseButtonEvent mouseButton, t_setting *sett)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(sett->blue);
    if (mouseButton.x >= 1050 && mouseButton.x <= 1105
        && mouseButton.y >= 500 && mouseButton.y <=  538)
        return (1);
    return (0);
}

int     is_on_red(sfMouseButtonEvent mouseButton, t_setting *sett)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(sett->red);
    if (mouseButton.x >= 990 && mouseButton.x <=  1045
        && mouseButton.y >= 500 && mouseButton.y <= 538)
        return (1);
    return (0);
}

void    set_rect(t_menu *menu, t_setting *opt)
{
    if (menu->color == GREEN) {
        menu->opt->rblue.left = 87;
        menu->opt->rred.left = 87;
        menu->opt->rgreen.left = 23;
        sfSprite_setTextureRect(opt->blue, opt->rblue);
        sfSprite_setTextureRect(opt->green, opt->rgreen);
        sfSprite_setTextureRect(opt->red, opt->rred);
    } else if (menu->color == BLUE) {
        menu->opt->rblue.left = 23;
        menu->opt->rred.left = 87;
        menu->opt->rgreen.left = 87;
        sfSprite_setTextureRect(opt->blue, opt->rblue);
        sfSprite_setTextureRect(opt->green, opt->rgreen);
        sfSprite_setTextureRect(opt->red, opt->rred);
    } else if (menu->color == RED) {
        menu->opt->rblue.left = 87;
        menu->opt->rred.left = 23;
        menu->opt->rgreen.left = 87;
        sfSprite_setTextureRect(opt->blue, opt->rblue);
        sfSprite_setTextureRect(opt->green, opt->rgreen);
        sfSprite_setTextureRect(opt->red, opt->rred);
    }
}

void    setting_event(sfMouseButtonEvent mouseButton, t_menu *menu)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(menu->opt->red);
    if (is_on_green(mouseButton, menu->opt)) {
        menu->color = GREEN;
    }
    else if (is_on_blue(mouseButton, menu->opt)) {
        menu->color = BLUE;
    }
    else if (is_on_red(mouseButton, menu->opt)) {
        menu->color = RED;
    }
    set_rect(menu, menu->opt);
}