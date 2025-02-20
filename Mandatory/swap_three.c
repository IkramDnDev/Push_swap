/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:42:56 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/18 16:53:17 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

static t_stack_node	*find_max_node(t_stack_node *stack)
{
	t_stack_node	*max_node;
	int				max;

	if (!stack)
		return (NULL);
	max_node = stack;
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	swap_three(t_stack_node **stack)
{
	t_stack_node	*max;

	max = find_max_node(*stack);
	if ((*stack) == max)
		ra(stack);
	if ((*stack)->next == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}
