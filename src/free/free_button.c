/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** free_button
*/

#include "rpg.h"

static void destroy_button(button_t *button)
{
    sfRectangleShape_destroy(button->shape);
    sfSprite_destroy(button->sprite);
    sfTexture_destroy(button->texture);
    sfMusic_stop(button->sound);
    sfMusic_destroy(button->sound);
}

static void destroy_big(main_game_t *game)
{
    destroy_button(game->btn->big->score_b);
    destroy_button(game->btn->big->resume_b);
    destroy_button(game->btn->big->help_b);
    destroy_button(game->btn->big->settings_b);
    destroy_button(game->btn->big->return_b);
    destroy_button(game->btn->big->play_b);
    destroy_button(game->btn->big->exit_b);
}

static void destroy_mid(main_game_t *game)
{
    destroy_button(game->btn->mid->main_b);
    destroy_button(game->btn->mid->top_sc_b);
    destroy_button(game->btn->mid->save_b);
    destroy_button(game->btn->mid->pause_b);
    destroy_button(game->btn->mid->right_b);
    destroy_button(game->btn->mid->mute_b);
    destroy_button(game->btn->mid->help_b);
    destroy_button(game->btn->mid->settings_b);
    destroy_button(game->btn->mid->exit_b);
    destroy_button(game->btn->mid->resume_b);
    destroy_button(game->btn->mid->left_b);
    destroy_button(game->btn->mid->unmute_b);
}

static void destroy_sml(main_game_t *game)
{
    destroy_button(game->btn->sml->plus_b);
    destroy_button(game->btn->sml->minus_b);
    destroy_button(game->btn->sml->talk_b);
    destroy_button(game->btn->sml->accept_b);
    destroy_button(game->btn->sml->deny_b);
    destroy_button(game->btn->sml->left_b);
    destroy_button(game->btn->sml->right_b);
    destroy_button(game->btn->sml->top_b);
    destroy_button(game->btn->sml->bot_b);
}

void destroy_all_button(main_game_t *game)
{
    destroy_big(game);
    destroy_mid(game);
    destroy_sml(game);
}