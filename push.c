/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:24:23 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/06 19:47:37 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void push(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *top;

    if (!a || !*a)
        return ;
    top = *a;
    *a = top->next;
    if (*a)
        (*a)->prev = NULL;
    top->next = *b;
    if (*b)
        (*b)->prev = top;
    *b = top;
}

void pa(t_stack_node **a, t_stack_node **b)
{
    push(a, b);
    write(1, "pa\n", 4);
}

void pb(t_stack_node **a, t_stack_node **b)
{
    push(b, a);
    write(1, "pb\n", 4);
}
