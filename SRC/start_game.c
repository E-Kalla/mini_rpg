/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** start_game
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

void    destroy_char(t_player *character)
{
    sfClock_destroy(character->clock);
    sfTexture_destroy(character->player);
    sfSprite_destroy(character->players);
}

void    destroy_game(t_game *game)
{
    sfRenderWindow_destroy(game->gamewindow);
    sfTexture_destroy(game->back);
    sfSprite_destroy(game->backs);
    sfMusic_destroy(game->music);
    sfMusic_destroy(game->click);
    sfSprite_destroy(game->cursors);
    sfTexture_destroy(game->pause);
    sfSprite_destroy(game->pauses);
    sfTexture_destroy(game->cursor);
    sfView_destroy(game->view);
    sfClock_destroy(game->mobspawn);
    destroy_char(game->character);
    destroy_quest(game->quest);
    destroy_pnj(game->npc);
    destroy_mob(game->allmob);
}

int    event_game_manager(t_game *game)
{
    while (sfRenderWindow_pollEvent(game->gamewindow, &game->event))
        {
            if (game->event.type == sfEvtClosed)
                sfRenderWindow_close(game->gamewindow);
            if (game->event.type == sfEvtMouseMoved && game->scene == PAUSE)
                event_game_moved(game->event.mouseMove,game);
            if (game->event.type == sfEvtKeyPressed)
                event_keygame(game->event.key, game);
        }
        return (0);
}

void    draw_game(t_game *game)
{
    sfRenderWindow_drawSprite(game->gamewindow, game->backs, NULL);
    draw_mob(game->allmob, game);
    draw_pnj(game->npc, game);
    if (game->scene == QUEST)
        sfRenderWindow_drawSprite(game->gamewindow, game->quest->quests,
        NULL);
    sfRenderWindow_drawSprite(game->gamewindow, game->character->players,
    NULL);
    if (game->scene == PAUSE) {
        sfRenderWindow_drawSprite(game->gamewindow, game->pauses, NULL);
    }
}

int     start_game(t_game *game)
{
    sfRenderWindow_setFramerateLimit(game->gamewindow, 60);
    sfRenderWindow_setMouseCursorVisible(game->gamewindow, sfFalse);
    sfMusic_play(game->music);
    sfRenderWindow_setView(game->gamewindow, game->view);
    while (sfRenderWindow_isOpen(game->gamewindow)) {
        time_handling(game);
        sfRenderWindow_clear(game->gamewindow, sfBlack);
        draw_game(game);
        event_game_manager(game);
        if (game->scene != PAUSE) {
            all_animation_manager(game);
            view_manager(game);
            mob_manage(game);
            pnj_manager(game);
            quest_core(game);
            sfRenderWindow_setView(game->gamewindow, game->view);
        }
        sfRenderWindow_display(game->gamewindow);
    }
    destroy_game(game);
    return (0);
}