/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "lib.h"
#include "rpg.h"
#include <SFML/Graphics.h>

int init_back_window(map_t *map, char ***tab, int i)
{
    map->back = malloc(sizeof(game_object_t));
    if (map->back == NULL)
        return EPITECH_ERROR;
    map->back->texture = sfTexture_createFromFile(tab[i][0], NULL);
    map->back->sprite = sfSprite_create();
    if (map->back->texture == NULL || map->back->sprite == NULL)
        return EPITECH_ERROR;
    sfSprite_setTexture(map->back->sprite, map->back->texture, sfFalse);
}

int init_map_window(map_t *map, char ***tab, int i)
{
    map->map = malloc(sizeof(game_object_t));
    if (map->map == NULL)
        return EPITECH_ERROR;
    map->map->texture = sfTexture_createFromFile(tab[i][0], NULL);
    map->map->sprite = sfSprite_create();
    if (map->map->texture == NULL || map->map->sprite == NULL)
        return EPITECH_ERROR;
    map->map->position.x = (my_atoi(tab[i][1]) * -1);
    map->map->position.y = (my_atoi(tab[i][2]) * -1);
    sfSprite_setTexture(map->map->sprite, map->map->texture, sfFalse);
}

int parse_tab(map_t *map, char ***tab, int i)
{
    if (my_arraylen(tab[i]) == -1)
        return EPITECH_ERROR;
    if (my_arraylen(tab[i]) == 1) {
        if (init_back_window(map, tab, i) == EPITECH_ERROR)
            return EPITECH_ERROR;
    }
    if (my_arraylen(tab[i]) == 3) {
        if (init_map_window(map, tab, i) == EPITECH_ERROR)
            return EPITECH_ERROR;
    }
    if (my_arraylen(tab[i]) == 7) {
        if (init_obstacle(map, tab, i) == EPITECH_ERROR)
            return EPITECH_ERROR;
    }
    if (my_arraylen(tab[i]) == 9) {
        if (init_mob(map, tab, i) == EPITECH_ERROR)
            return EPITECH_ERROR;
    }
    return EXIT_SUCCESS;
}
