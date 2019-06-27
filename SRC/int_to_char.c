/*
** EPITECH PROJECT, 2018
** putnbr
** File description:
** nbr
*/

#include <stdlib.h>
#include <stdio.h>
#include "../rpg.h"

int digicount(int n)
{
    int result = 0;
    int i = 1;

    while (i == 1 || n != 0) {
        i = 0;
        n = n / 10;
        result = result + 1;
    }
    return (result);
}

int power(int n)
{
    int power = 1;

    while (n > 1) {
        power = power * 10;
        n = n - 1;
    }
    return (power);
}

char *score_to_string(int score)
{
    int mod = 0;
    int tmp = 0;
    int i = 0;
    int digit_count = digicount(score);;
    char *point = malloc(sizeof(*point) * (digit_count + 1));

    while (digit_count > 0) {
        tmp = score / power(digit_count);
        mod = tmp % 10;
        point[i] =  mod + 48;
        i += 1;
        digit_count -= 1;
    }
    point[i] = 0;
    return (point);
}
