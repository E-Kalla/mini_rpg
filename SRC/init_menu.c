/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_menu
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    more_setting(t_setting *opt)
{
    sfSprite_setTextureRect(opt->blue, opt->rblue);
    sfSprite_setTextureRect(opt->green, opt->rgreen);
    sfSprite_setTextureRect(opt->red, opt->rred);
    opt->vgreen.y = 500;
    opt->vgreen.x = 930;
    opt->vred.y = 500;
    opt->vred.x = 990;
    opt->vblue.y = 500;
    opt->vblue.x = 1050;
    sfSprite_setPosition(opt->green, opt->vgreen);
    sfSprite_setPosition(opt->red, opt->vred);
    sfSprite_setPosition(opt->blue, opt->vblue);
}

void    init_setting(t_menu *menu)
{
    menu->opt = malloc(sizeof(t_setting));
    menu->opt->sett = sfTexture_createFromFile("IMG/void.png", NULL);
    menu->opt->red = sfSprite_create();
    menu->opt->blue = sfSprite_create();
    menu->opt->green = sfSprite_create();
    sfSprite_setTexture(menu->opt->red, menu->opt->sett, sfTrue);
    sfSprite_setTexture(menu->opt->blue, menu->opt->sett, sfTrue);
    sfSprite_setTexture(menu->opt->green, menu->opt->sett, sfTrue);
    menu->opt->rblue.top = 62;
    menu->opt->rblue.left = 87;
    menu->opt->rblue.width = 55;
    menu->opt->rblue.height = 38;
    menu->opt->rred.top = 111;
    menu->opt->rred.left = 87;
    menu->opt->rred.width = 55;
    menu->opt->rred.height = 38;
    menu->opt->rgreen.top = 15;
    menu->opt->rgreen.left = 23;
    menu->opt->rgreen.width = 55;
    menu->opt->rgreen.height = 38;
    more_setting(menu->opt);
}

void    init_more_menu2(t_menu *menu)
{
    menu->onplay = sfTexture_createFromFile("IMG/startmouse.png", NULL);
    menu->playclick = sfTexture_createFromFile("IMG/startclick.png", NULL);
    menu->onexit = sfTexture_createFromFile("IMG/exitmouse.png", NULL);
    menu->exitclick = sfTexture_createFromFile("IMG/exitclick.png", NULL);
    menu->settings = sfSprite_create();
    menu->setting = sfTexture_createFromFile("IMG/settingzelda.png", NULL);
    sfSprite_setTexture(menu->settings, menu->setting, sfTrue);
    menu->vsetting.x = 663;
    menu->vsetting.y = 250;
    sfSprite_setPosition(menu->settings, menu->vsetting);
    init_setting(menu);
}

void    init_more_menu(t_menu *menu)
{
    menu->vplay.x = 400;
    menu->vplay.y = 100;
    menu->vexit.x = 800;
    menu->vexit.y = 100;
    menu->vopt.x = 1300;
    menu->vopt.y = 100;
    sfSprite_setPosition(menu->exitbuttons, menu->vexit);
    sfSprite_setPosition(menu->playbuttons, menu->vplay);
    sfSprite_setPosition(menu->settingbuttons, menu->vopt);
    menu->onsetting = sfTexture_createFromFile("IMG/settingmouse.png", NULL);
    menu->settingclick = sfTexture_createFromFile("IMG/settingclick.png",
    NULL);
    menu->cursor = sfTexture_createFromFile("IMG/cursortest.png", NULL);
    menu->cursors = sfSprite_create();
    sfSprite_setTexture(menu->cursors, menu->cursor, sfTrue);
    menu->color = GREEN;
    menu->scene = MENU;
    init_more_menu2(menu);
}

void    initialise_menu(t_menu *menu)
{
    sfVideoMode mode = {1920, 1080, 32};
    menu->back = sfTexture_createFromFile("IMG/menu5.jpg", NULL);
    menu->backs = sfSprite_create();
    menu->playbutton = sfTexture_createFromFile("IMG/basicstarto.png", NULL);
    menu->playbuttons = sfSprite_create();
    menu->settingbutton = sfTexture_createFromFile("IMG/setting.png", NULL);
    menu->settingbuttons = sfSprite_create();
    menu->exitbutton = sfTexture_createFromFile("IMG/exit.png", NULL);
    menu->exitbuttons = sfSprite_create();
    menu->menuwindow = sfRenderWindow_create(mode, "MyRPG - Menu", sfResize
    | sfClose, NULL);
    sfSprite_setTexture(menu->backs, menu->back, sfTrue);
    sfSprite_setTexture(menu->settingbuttons, menu->settingbutton, sfTrue);
    sfSprite_setTexture(menu->playbuttons, menu->playbutton, sfTrue);
    sfSprite_setTexture(menu->exitbuttons, menu->exitbutton, sfTrue);
    menu->music = sfMusic_createFromFile("SOUND/menu.ogg");
    menu->click = sfMusic_createFromFile("SOUND/clickmenu.wav");
    sfMusic_setVolume(menu->click,50);
    sfMusic_setLoop(menu->music, 1);
    sfMusic_setVolume(menu->music,30);
    init_more_menu(menu);
}