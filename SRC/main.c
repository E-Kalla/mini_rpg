/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** kill duck
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../rpg.h"

int     main(int ac, char **argv)
{
    if (ac != 1)
        return (84);
    t_menu menu;
    initialise_menu(&menu);
    start_menu(&menu);
    return (0);
}