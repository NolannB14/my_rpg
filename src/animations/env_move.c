/*
** EPITECH PROJECT, 2022
** env_mouve
** File description:
** env_mouve
*/

#include "rpg.h"

void move_up(map_t *map, player_t *player)
{
    obstacle_t *obstacle = map->obstacle;
    mobe_t *mobe = map->mobe;
    particles_t *dust = creat_particles(0, player->object->position, 10,
    (sfVector2f){6, 10});

    player->dust = add_particle_to_list(player->dust, dust,
    (sfVector2f){0, 10});
    map->map->position.y += 10;
    while (obstacle != NULL) {
        if (map->map->position.y <= 607) {
            obstacle->object->position.y += 10;
            sfSprite_setPosition(obstacle->object->sprite,
            obstacle->object->position);
        }
        obstacle = obstacle->next;
    }
    while (mobe != NULL) {
        if (map->map->position.y <= 607) {
            mobe->object->position.y += 10;
            sfSprite_setPosition(map->mobe->object->sprite,
            mobe->object->position);
        }
        mobe = mobe->next;
    }
    sfSprite_setPosition(map->map->sprite, map->map->position);
}

void move_down(map_t *map, player_t *player)
{
    obstacle_t *obstacle = map->obstacle;
    mobe_t *mobe = map->mobe;
    particles_t *dust = creat_particles(0, player->object->position, 10,
    (sfVector2f){6, -10});

    player->dust = add_particle_to_list(player->dust, dust,
    (sfVector2f){0, -10});
    map->map->position.y -= 10;
    while (obstacle != NULL) {
        if (map->map->position.y >= -3403) {
            obstacle->object->position.y -= 10;
            sfSprite_setPosition(obstacle->object->sprite,
            obstacle->object->position);
        }
        obstacle = obstacle->next;
    }
    while (mobe != NULL) {
        if (map->map->position.y >= -3403) {
            mobe->object->position.y -= 10;
            sfSprite_setPosition(map->mobe->object->sprite,
            mobe->object->position);
        }
        mobe = mobe->next;
    }
    sfSprite_setPosition(map->map->sprite, map->map->position);
}

void move_right(map_t *map, player_t *player)
{
    obstacle_t *obstacle = map->obstacle;
    mobe_t *mobe = map->mobe;
    particles_t *dust = creat_particles(0, player->object->position, 10,
    (sfVector2f){0, -10});

    player->dust = add_particle_to_list(player->dust, dust,
    (sfVector2f){-10, 0});
    map->map->position.x -= 10;
    while (obstacle != NULL) {
        if (map->map->position.x >= -3098) {
            obstacle->object->position.x -= 10;
            sfSprite_setPosition(obstacle->object->sprite, \
            obstacle->object->position);
        }
        obstacle = obstacle->next;
    }
    while (mobe != NULL) {
        if (map->map->position.x >= -3098) {
            mobe->object->position.x -= 10;
            sfSprite_setPosition(mobe->object->sprite,
            mobe->object->position);
        }
        mobe = mobe->next;
    }
    sfSprite_setPosition(map->map->sprite, map->map->position);
}

void move_left(map_t *map, player_t *player)
{
    obstacle_t *obstacle = map->obstacle;
    mobe_t *mobe = map->mobe;
    particles_t *dust = creat_particles(0, player->object->position, 10,
    (sfVector2f){0, -10});

    player->dust = add_particle_to_list(player->dust, dust,
    (sfVector2f){10, 0});
    map->map->position.x += 10;
    while (obstacle != NULL) {
        if (map->map->position.x <= 922) {
            obstacle->object->position.x += 10;
            sfSprite_setPosition(obstacle->object->sprite, \
            obstacle->object->position);
        }
        obstacle = obstacle->next;
    }
    while (mobe != NULL) {
        if (map->map->position.x <= 922) {
            mobe->object->position.x += 10;
            sfSprite_setPosition(mobe->object->sprite,
            mobe->object->position);
        }
        mobe = mobe->next;
    }
    sfSprite_setPosition(map->map->sprite, map->map->position);
}
