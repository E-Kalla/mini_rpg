/*
** EPITECH PROJECT, 2018
** my hunter
** File description:
** rpg.h
*/

#ifndef RPG_H_
	#define RPG_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#define TRUE (1)
#define FALSE (0)
#define NORTH (10)
#define EST (11)
#define WEST (12)
#define SOUTH (13)
#define MAP (99)
#define PAUSE (100)
#define SETTING (200)
#define MENU (300)
#define BLUE (23)
#define GREEN (24)
#define RED (25)
#define RESUME (50)
#define EXIT (51)
#define QUEST (66)
#define COMPLETE (11)
#define CURRENT (12)
#define NOT (13)

typedef struct parammob_s {
    sfTexture *mob;
    sfSprite *mobs;
    sfClock *clock;
    sfTime timer;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f mov;
    sfMusic *scream;
    sfTexture *life;
    sfSprite *lifes;
    sfIntRect reclife;
    int step;
    bool alive;
    float second;
    int hp;
    int strenght;
    int smart;
    int agility;
    int mana;
    int orientation;
} t_parammob;

typedef struct mob_s {
    sfTexture *mob;
    sfSprite *mobs;
    sfClock *clock;
    sfTime timer;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f mov;
    sfMusic *scream;
    sfTexture *life;
    sfSprite *lifes;
    sfTexture *stat;
    sfSprite *stats;
    sfVector2f vstat;
    sfIntRect reclife;
    int step;
    bool alive;
    float second;
    int hp;
    int strenght;
    int smart;
    int agility;
    int mana;
    int orientation;
    struct mob_s *next;
    struct mob_s *prev;
} t_mob;

typedef struct pnj_s {
    sfTexture *pnj;
    sfSprite *pnjs;
    sfTexture *stat;
    sfSprite *stats;
    sfClock *clock;
    sfTime timer;
    sfVector2f vstats;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f mov;
    int orientation;
    char name[20];
    int step;
    int status;
    struct pnj_s *next;
    struct pnj_s *prev;
} t_pnj;

typedef struct list_mob_s {
    int nb;
    t_mob *first;
    t_mob *last;
} t_list_mob;

typedef struct paramwall_s {
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *rec;
} t_paramwall;

typedef struct wall_s {
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *rect;
    struct wall_s *next;
    struct wall_s *prev;
} t_wall;

typedef struct list_wall_s {
    int nb;
    t_wall *first;
    t_wall *last;
} t_list_wall;

typedef struct list_pnj_s {
    int nb;
    t_pnj *first;
    t_pnj *last;
} t_list_pnj;

typedef struct player_s {
    sfTexture *player;
    sfSprite *players;
    sfTexture *life;
    sfSprite *lifes;
    sfIntRect reclife;
    sfClock *clock;
    sfTime timer;
    sfIntRect rectp;
    sfVector2f position;
    sfVector2f move;
    float second;
    int attack;
    int hp;
    int strenght;
    int smart;
    int agility;
    int mana;
    bool moving;
    int orientation;
} t_player;

typedef struct quest_s {
    sfTexture *quest;
    sfSprite *quests;
    sfVector2f rquest;
    sfIntRect which;
    int statfirst;
    int statsecond;
    int statthird;
    int obj;
} t_quest;

typedef struct game_s {
    sfTexture *pause;
    sfIntRect rpause;
    sfSprite *pauses;
    int pausestatut;
    sfIntRect resume;
    sfIntRect exit;
    sfTexture *back;
    sfSprite *backs;
    sfTexture *cursor;
    sfSprite *cursors;
    sfMusic *music;
    sfMusic *click;
    sfRenderWindow *gamewindow;
    sfClock *gameclock;
    sfClock *mobspawn;
    sfTime timeg;
    sfEvent event;
    sfView *view;
    sfVector2f viewcenter;
    sfVector2f viewsize;
    sfVector2f vpause;
    t_player *character;
    t_list_mob *allmob;
    t_list_wall *allwall;
    t_list_pnj *npc;
    t_quest *quest;
    int speed;
    int color;
    int scene;
    float second;
    float spawning;
    int multiplayer;
} t_game;

typedef struct setting_s {
    sfTexture *sett;
    sfSprite *blue;
    sfSprite *red;
    sfSprite *green;
    sfVector2f vblue;
    sfVector2f vred;
    sfVector2f vgreen;
    sfIntRect rblue;
    sfIntRect rred;
    sfIntRect rgreen;
} t_setting;

typedef struct menu_s {
    sfFont *Font;
    sfVector2f vplay;
    sfVector2f vexit;
    sfVector2f vopt;
    sfVector2f vsetting;
    sfTexture *cursor;
    sfSprite *cursors;
    sfTexture *back;
    sfSprite *backs;
    sfTexture *playbutton;
    sfSprite *playbuttons;
    sfTexture *onplay;
    sfTexture *playclick;
    sfTexture *exitbutton;
    sfSprite *exitbuttons;
    sfTexture *onexit;
    sfTexture *exitclick;
    sfTexture *settingbutton;
    sfSprite *settingbuttons;
    sfTexture *onsetting;
    sfTexture *settingclick;
    sfMusic *music;
    sfRenderWindow *menuwindow;
    sfTexture *setting;
    sfSprite *settings;
    sfClock *clock;
    sfTime time;
    t_setting *opt;
    int scene;
    int color;
    float seconds;
    sfEvent event;
    int on;
    int multiplayer;
    sfMusic *click;
} t_menu;

void    init_wall(t_game *game);
void    destroy_menu(t_menu *menu);
int     die_mob(t_list_mob *allmob);
bool    check_quest_one(t_game *games);
bool    check_quest_two(t_game *games);
bool    check_quest_three(t_game *games);
void    destroy_quest(t_quest *quest);
void    destroy_pnj(t_list_pnj *npc);
void    pnj_manager(t_game *game);
void    draw_pnj(t_list_pnj *npc, t_game *game);
t_list_pnj *addpnj(t_list_pnj *npc);
t_list_pnj *init_npc(void);
void    quest_core(t_game *games);
char    *my_strdup(char *dest, char *src);
void    init_quest(t_game *games);
void    destroy_setting(t_setting *setting);
void    setting_event(sfMouseButtonEvent mouseButton, t_menu *menu);
void    *kill_mob(t_list_mob *allmob);
void    destroy_mob(t_list_mob *allmob);
void    attack_hit(t_game *game);
void    mob1_rect(t_list_mob *allmob);
void    mob1_movement(t_list_mob *allmob);
void    draw_mob(t_list_mob *allmob, t_game *game);
void    configure_mob1(t_parammob *newmob);
void    mob_manage(t_game *game);
void    init_mob(t_game *game);
bool    can_up_camera(t_game *game);
bool    can_down_camera(t_game *game);
bool    can_left_camera(t_game *game);
bool    can_right_camera(t_game *game);
void    view_manager(t_game *game);
void    basic_attack_left(t_player *character, t_game *game);
void    basic_attack_right(t_player *character, t_game *game);
void    basic_attack_up(t_player *character, t_game *game);
void    basic_attack_down(t_player *character, t_game *game);
void    all_animation_manager(t_game *game);
void    time_handling(t_game *game);
void    basic_attack(t_game *game);
bool valid_right_move(sfFloatRect box, t_list_wall *allwall, float speed);
bool valid_left_move(sfFloatRect box, t_list_wall *allwall, float speed);
bool valid_up_move(sfFloatRect box, t_list_wall *allwall, float speed);
bool valid_down_move(sfFloatRect box, t_list_wall *allwall, float speed);
t_list_mob  *add_mob(t_list_mob *list, t_parammob *mob);
t_list_wall  *add_wall(t_list_wall *list, t_paramwall *opt);
t_list_mob *init_list_mob(void);
t_list_wall *init_list_wall(void);
void    more_wall6(t_game *game);
void    more_wall(t_game *game);
void    move_down_rect(t_player *character);
void    move_up_rect(t_player *character);
void    move_left_rect(t_player *character);
void    move_right_rect(t_player *character);
void    move_left(t_game *game);
void    move_right(t_game *game);
void    move_up(t_game *game);
void    move_down(t_game *game);
void    event_keygame(sfKeyEvent key, t_game *game);
void    event_game_moved(sfMouseMoveEvent move, t_game *game);
void    init_game(t_game *game, t_menu *menu);
int     start_game(t_game *game);
void    event_menu_moved(sfMouseMoveEvent move, t_menu *menu);
int     event_click(sfMouseButtonEvent mouseButton, t_menu *menu);
int     start_menu(t_menu *menu);
void    initialise_menu(t_menu *menu);
int     check_arg(int ac, char **argv);
void    display_desc(void);
char    *my_evil_str(char *str);
char    *score_to_string(int score);
void	my_putchar(char n);
int 	my_putstr(char const *str);
int     my_strlen(char const *str);

#endif