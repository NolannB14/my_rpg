/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-adrien.ricou
** File description:
** button_pos_menu
*/

#include "rpg.h"

static void pos_fullscreen(main_game_t *game)
{
    sfRectangleShape_setPosition(game->btn->mid->help_b->shape,
    game->btn->mid->help_b->position);
    sfRectangleShape_setPosition(game->btn->big->exit_b->shape,
    game->btn->big->exit_b->position);
    sfRectangleShape_setPosition(game->btn->big->return_b->shape,
    game->btn->big->return_b->position);
}

void pos_button_keybind(main_game_t *game)
{
    float win_x = MAX_W_X;
    float win_y = MAX_W_Y;
    sfVector2u size = sfRenderWindow_getSize(game->w);

    game->btn->mid->help_b->position = POS_HELP;
    game->btn->big->exit_b->position = POS_EXIT;
    game->btn->big->return_b->position = POS_RETURN;
    sfSprite_setPosition(game->btn->mid->help_b->sprite,
    game->btn->mid->help_b->position);
    sfSprite_setPosition(game->btn->big->exit_b->sprite,
    game->btn->big->exit_b->position);
    sfSprite_setPosition(game->btn->big->return_b->sprite,
    game->btn->big->return_b->position);
    if (size.x == MAX_W_X && size.y == MAX_W_Y)
        pos_fullscreen(game);
    else {
        resize_all_buttons(game, ((float){size.x} / win_x),
        ((float){size.y} / win_y));
    }
}
