/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list_function.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:07:13 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/04 14:26:07 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* deallocate : sur 3 node tu commence a la node2 pour deallocate la 1, ensuite tu avance et deallocate la 2...
* a la fin (apres loop) tu deallcate celle qui reste 
*/

#include "../includes/push_swap.h"

void insert_end(t_stack_element **head, int value)
{
    t_stack_element *new_node;
    
    new_node =  malloc(sizeof(t_stack_element));
    if (new_node == NULL)
        exit(1);
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = *head;
    //
    if (*head != NULL)
        (*head)->next = new_node;
    *head = new_node;
}

void deallocate(t_stack_element **tail, t_stack_element **head)
{
    if (*tail == NULL)
        return;
    t_stack_element *curr = *tail;
    while (curr->next != NULL)
    {
        curr = curr->next;
        free(curr->prev);
    }
    free(curr);
    
    *tail = NULL;
    *head = NULL;
}