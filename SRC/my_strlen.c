/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** A function that counts and returns the number of characters found
*/

#include "../rpg.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}