/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** Can copy str
*/

#include "../rpg.h"

char *my_strdup(char *dest, char *src)
{
    int i = 0;
    int len = my_strlen(src);
    dest = malloc(sizeof(char) * len + 1);

    while (src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
        }
    dest[i] = '\0';
    return (dest);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
        }
    dest[i] = '\0';
    return (dest);
}
