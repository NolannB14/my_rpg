/*
** EPITECH PROJECT, 2021
** node
** File description:
** lemin
*/

#include "rpg.h"

obstacle_t *add_node_to_obstacle(obstacle_t *head, obstacle_t *node)
{
    obstacle_t *tmp = head;

    if (head == NULL) {
        head = node;
    } else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
    return head;
}

speobstacle_t *add_node_to_speobstacle(speobstacle_t *head, speobstacle_t
*node)
{
    speobstacle_t *tmp = head;

    if (head == NULL) {
        head = node;
    } else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
    return head;
}

mobe_t *add_node_to_mobe(mobe_t *head, mobe_t *node)
{
    mobe_t *tmp = head;

    if (head == NULL) {
        head = node;
    } else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
    return head;
}
