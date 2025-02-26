/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:44:47 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/26 13:02:42 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "checker.h"

void	rotate_reverse(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*first;
	t_stack_node	*new_last;

	if (!stack || !*stack)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	new_last = last->prev;
	if (new_last)
		new_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
}

void	rra(t_stack_node **a)
{
	rotate_reverse(a);
}

void	rrb(t_stack_node **b)
{
	rotate_reverse(b);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rotate_reverse(a);
	rotate_reverse(b);
}
