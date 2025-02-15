/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:46:28 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/15 16:29:08 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	set_current_pos(t_stack_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = len_stack(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	a_len;
	int	b_len;

	a_len = len_stack(a);
	b_len = len_stack(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = b_len - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += a_len - (b->target_node->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!b)
		return ;
	cheapest_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < cheapest_value)
		{
			cheapest_value = b->push_price;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node;
	t_stack_node	*current_a;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_pos(a);
	set_current_pos(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
