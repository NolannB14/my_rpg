/*
** EPITECH PROJECT, 2022
** init_player
** File description:
** init_player
*/

#include "rpg.h"

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->life = 20;
    player->attack = 5;
    player->object = malloc(sizeof(game_object_t));
    player->object->position = (sfVector2f){960, 600};
    player->object->scale = (sfVector2f){4, 4};
    player->object->rect = (sfIntRect){0, 0, 48, 48};
    player->p_clock = init_clock();
    player->object->texture = sfTexture_createFromFile(PLAYER_SS, NULL);
    if (!player->object->texture)
        return NULL;
    player->object->sprite = sfSprite_create();
    if (!player->object->sprite)
        return NULL;
    sfSprite_setOrigin(player->object->sprite, (sfVector2f){24, 24});
    sfSprite_setTexture(player->object->sprite, player->object->texture, sfTrue);
    sfSprite_setTextureRect(player->object->sprite, player->object->rect);
    sfSprite_setScale(player->object->sprite, player->object->scale);
    sfSprite_setPosition(player->object->sprite, player->object->position);
    return player;
}
