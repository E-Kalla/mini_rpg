/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_game
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"



void    init_pause(t_game *game)
{
    init_quest(game);
    game->speed = 0;
    game->vpause = game->viewcenter;
    game->pausestatut = RESUME;
    game->vpause.y -= 100;
    game->vpause.x -= 100;
    game->rpause.top = 21;
    game->rpause.left = 176;
    game->rpause.width = 220;
    game->rpause.height = 187;
    game->pause = sfTexture_createFromFile("IMG/vide.png", NULL);
    game->pauses = sfSprite_create();
    sfSprite_setTexture(game->pauses, game->pause, sfTrue);
    sfSprite_setTextureRect(game->pauses, game->rpause);
    sfSprite_setPosition(game->pauses, game->vpause);
}

void    init_player(t_game *game)
{
    sfVector2i mo;
    game->npc = init_npc();
    game->npc = addpnj(game->npc);
    mo.x = 209;
    mo.y = 1990;
    init_pause(game);
    game->scene = MAP;
    if (game->color == GREEN)
        game->character->player = sfTexture_createFromFile("IMG/player.png",
        NULL);
    else if (game->color == BLUE)
        game->character->player = sfTexture_createFromFile("IMG/blue.png",
        NULL);
    else if (game->color == RED)
        game->character->player = sfTexture_createFromFile("IMG/red.png",
        NULL);
}

void    init_more_game(t_game *game)
{
    init_player(game);
    game->character->players = sfSprite_create();
    game->character->hp = 100;
    game->character->position.x = 200;
    game->character->position.y = 1985;
    game->character->rectp.top = 10;
    game->character->rectp.left = 120;
    game->character->rectp.width = 20;
    game->character->rectp.height = 25;
    game->character->moving = false;
    game->character->clock = sfClock_create();
    sfSprite_setTexture(game->character->players,
    game->character->player, sfTrue);
    sfSprite_setPosition(game->character->players, game->character->position);
    sfSprite_setTextureRect(game->character->players, game->character->rectp);
    init_wall(game);
    init_mob(game);
}

void    init_game2(t_game *game, t_menu *menu)
{
    game->cursor = sfTexture_createFromFile("IMG/cursortest.png", NULL);
    game->cursors = sfSprite_create();
    game->mobspawn = sfClock_create();
    sfSprite_setTexture(game->cursors, game->cursor, sfTrue);
    game->viewcenter.x = 200;
    game->viewcenter.y = 1985;
    game->viewsize.x = 400;
    game->viewsize.y = 300;
    game->view = sfView_create();
}

void    init_game(t_game *game, t_menu *menu)
{
    game->character = malloc(sizeof(t_player));
    sfVideoMode mode = {1920, 1080, 32};
    game->color = menu->color;
    game->back = sfTexture_createFromFile("IMG/map.png",NULL);
    game->backs = sfSprite_create();
    game->gamewindow = sfRenderWindow_create(mode, "MyRPG - Game", sfResize
    | sfClose, NULL);
    sfSprite_setTexture(game->backs, game->back, sfTrue);
    game->music = sfMusic_createFromFile("SOUND/menu.ogg");
    game->click = sfMusic_createFromFile("SOUND/clickmenu.wav");
    sfMusic_setVolume(game->click,50);
    sfMusic_setLoop(game->music, 1);
    sfMusic_setVolume(game->music,30);
    init_game2(game, menu);
    sfView_setCenter(game->view, game->viewcenter);
    sfView_setSize(game->view, game->viewsize);
    init_more_game(game);
}