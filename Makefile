##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Make bsq
##

SRC		=	./SRC/main.c	\
			./SRC/int_to_char.c	\
			./SRC/my_pustr.c    \
			./SRC/my_putchar.c  \
			./SRC/init_menu.c   \
			./SRC/start_menu.c  \
			./SRC/event_menu.c  \
			./SRC/event_menu2.c \
			./SRC/init_game.c   \
			./SRC/start_game.c  \
			./SRC/event_game_move.c \
			./SRC/event_keygame.c   \
			./SRC/movement.c    \
			./SRC/rect_player_manage.c  \
			./SRC/init_list.c   \
			./SRC/fill_list1.c  \
			./SRC/valid_move.c  \
			./SRC/wall_manager.c    \
			./SRC/wall_manager2.c   \
			./SRC/player_attack.c   \
			./SRC/time.c    \
			./SRC/all_deplacement.c \
			./SRC/view.c    \
			./SRC/camera.c  \
			./SRC/init_mob.c    \
			./SRC/spawn_mob.c   \
			./SRC/mob1.c    \
			./SRC/attack_hit.c  \
			./SRC/destroy_mob.c \
			./SRC/setting_event.c   \
			./SRC/destroy_setting.c \
			./SRC/quest.c   \
			./SRC/my_strcpy.c   \
			./SRC/my_strlen.c   \
			./SRC/pnj.c \
			./SRC/pnj_manage.c  \
			./SRC/destroy_pnj.c \
			./SRC/destroy_quest.c   \
			./SRC/check_quest.c \
			./SRC/destroy_menu.c    \
			./SRC/wall.c

OBJ 	= 	$(SRC:.c=.o)

NAME	=	my_rpg

$(NAME) : $(OBJ)
		gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-system -l csfml-audio
all:	$(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:
		fclean all
