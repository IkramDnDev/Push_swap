/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:39:29 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/13 11:41:29 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

static t_stack_node	*stack_new(int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

static void	stack_add_back(t_stack_node **stack, t_stack_node *new_node)
{
	t_stack_node	*tmp;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
}

t_stack_node	*init_stack(char **av)
{
	t_stack_node	*stack;
	int				value;
	int				i;

	stack = NULL;
	i = 0;
	while (av[i])
	{
		value = ft_atoi(av[i]);
		stack_add_back(&stack, stack_new(value));
		i++;
	}
	return (stack);
}
