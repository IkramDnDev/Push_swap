/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:07:09 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/08 17:07:07 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void rotate_reverse(t_stack_node **stack)
{
    t_stack_node *last;
    t_stack_node *first;
    t_stack_node *new_last;
    
    first = *stack;
    last = *stack;
    while(last->next)
        last = last->next;

    new_last = last->prev;
    
    if (new_last) 
        new_last->next = NULL;
    last->prev = NULL;
    last->next = first;
    first->prev = last;

    *stack = last;
}

void rra(t_stack_node **a)
{
    rotate_reverse(a);
    write(1, "rra\n",5);
}

void rrb(t_stack_node **b)
{
    rotate_reverse(b);
    write(1, "rrb\n",5);
}

void rrr(t_stack_node **a, t_stack_node **b)
{
    rotate_reverse(a);
    rotate_reverse(b);
    write(1, "rrr\n",5);
}