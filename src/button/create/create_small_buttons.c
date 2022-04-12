/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_small_buttons
*/

#include "rpg.h"

static int create_small_buttons(main_game_t *game)
{
    char **tab = init_button_rsc2(BUTTON_SOUND, BUTTON_SS);

    if (init_button(&(game->btn->sml->plus_b), (sfVector2f){750, 700},
    SMALL, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->sml->minus_b), (sfVector2f){750, 700},
    SMALL, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->sml->talk_b), (sfVector2f){750, 700},
    SMALL, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->sml->accept_b), (sfVector2f){750, 700},
    SMALL, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->sml->deny_b), (sfVector2f){750, 700},
    SMALL, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

static int create_small_buttons2(main_game_t *game)
{
    char **tab = init_button_rsc2(BUTTON_SOUND, BUTTON_SS);

    if (init_button(&(game->btn->sml->left_b), (sfVector2f){750, 700},
    SMALL, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->sml->right_b), (sfVector2f){750, 700},
    SMALL, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->sml->top_b), (sfVector2f){750, 700},
    SMALL, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (init_button(&(game->btn->sml->bot_b), (sfVector2f){750, 700},
    SMALL, tab) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}

int create_all_small_buttons(main_game_t *game)
{
    char **tab = init_button_rsc2(BUTTON_SOUND, BUTTON_SS);

    if (create_small_buttons(game) == EPITECH_ERROR
    || create_small_buttons2(game) == EPITECH_ERROR)
        return EPITECH_ERROR;
    return EXIT_SUCCESS;
}