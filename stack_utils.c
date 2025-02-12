/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:33:48 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/12 17:57:16 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL;
}

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min_node;
	int				min;

	min_node = stack;
	min = stack->value;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

int	len_stack(t_stack_node *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		++i;
		stack = stack->next;
	}
	return (i);
}
