/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "rpg.h"

int main(const int argc, char const *argv[], char **env)
{
    if (!argv || !env || manage_errors(argc, env) == 84)
        return EPITECH_ERROR;
    return rpg();
}
