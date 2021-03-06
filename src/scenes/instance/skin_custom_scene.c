/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu_scene
*/

#include "rpg.h"

static const event_t event_array[] = {
    {.type = sfEvtClosed, .events = &close_window, .index = 0},
    {.type = -1, .events = NULL, .index = -1}
};

static int skin_scene_event(main_game_t *game)
{
    const event_t *event = get_event(game->event.type, event_array);

    if (event)
        return event->events(game);
    return game->player->current_scene;
}

static int manage_button_action_scene(main_game_t *game, sfVector2i mouse_pos)
{
    if (button_is_clicked(game->btn->big->return_b, mouse_pos) == true) {
        clicked_state_custom_skin(game, game->btn->big->return_b->shape,
        POS_RETURN3);
        sfSprite_setColor(game->player->object->sprite,
        sfColor_fromRGB(255, 255, 255));
        return game->player->next_scene = SAVE_SCENE;
    }
    if (button_is_clicked(game->btn->big->play_b, mouse_pos) == true) {
        clicked_state_custom_skin(game, game->btn->big->play_b->shape,
        POS_PLAY);
        return game->player->next_scene = GAME_SCENE;
    }
    if (button_is_clicked(game->btn->mid->exit_b, mouse_pos) == true) {
        clicked_state_custom_skin(game, game->btn->mid->exit_b->shape,
        POS_HELP);
        return close_window(game);
    }
    return game->player->current_scene;
}

static int manage_button_action(main_game_t *game, sfVector2i mouse_pos)
{
    event_skin_choice(game, mouse_pos);
    if (manage_button_action_scene(game, mouse_pos)
        != game->player->current_scene)
        return game->player->next_scene;
    if (button_is_clicked(game->btn->sml->right_b, mouse_pos) == true)
        set_rgb_right(game);
    if (button_is_clicked(game->btn->sml->left_b, mouse_pos) == true)
        set_rgb_left(game);
    return game->player->current_scene;
}

static int skin_check_events(main_game_t *game, sfVector2i mouse_pos)
{
    while (sfRenderWindow_pollEvent(game->w, &game->event)) {
        if (game->event.type == sfEvtMouseButtonPressed)
            return manage_button_action(game, mouse_pos);
        if (skin_scene_event(game) != game->player->current_scene)
            return game->player->next_scene;
        if (game->event.key.code == game->keys->quit && game->event.type
            == sfEvtKeyPressed)
            return close_window(game);
    }
    return game->player->current_scene;
}

int skin_scene(main_game_t *game)
{
    sfVector2i mouse_pos;

    starting_skin_scene(game);
    while (sfRenderWindow_isOpen(game->w)) {
        sfView_reset(game->basic_view, VIEW_SIZE);
        sfRenderWindow_setView(game->w, game->basic_view);
        mouse_pos = sfMouse_getPositionRenderWindow(game->w);
        sfRenderWindow_clear(game->w, sfWhite);
        manage_all_hover(game, mouse_pos);
        player_animations(game->player, game->map->mobe);
        if (skin_check_events(game, mouse_pos)
            != game->player->current_scene) {
            sfMusic_stop(game->btn->big->play_b->sound);
            return game->player->next_scene;
        }
        display_skin_cus(game);
        sfRenderWindow_display(game->w);
    }
    return EXIT_SUCCESS;
}
