/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** clicked_state
*/

#include "rpg.h"

void clicked_state_pause(main_game_t *game, sfRectangleShape *shape)
{
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    while (seconds < 0.2) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        sfMusic_play(game->btn->mid->pause_b->sound);
        display_pause(game);
        sfRenderWindow_drawRectangleShape(game->w, shape, NULL);
        sfRenderWindow_display(game->w);
    }
    sfMusic_stop(game->btn->mid->pause_b->sound);
    sfClock_destroy(clock);
}
