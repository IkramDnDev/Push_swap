/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:48:27 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/25 12:29:31 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

static void	r_a_b(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b);
	set_pos(*a);
	set_pos(*b);
}

static void	rr_a_b(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b);
	set_pos(*a);
	set_pos(*b);
}

static void	final_rotation(t_stack_node **stack, t_stack_node *top_node,
		char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		r_a_b(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rr_a_b(a, b, cheapest_node);
	final_rotation(b, cheapest_node, 'b');
	final_rotation(a, cheapest_node->target_node, 'a');
	pa(b, a);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int				len_a;
	t_stack_node	*min;

	len_a = len_stack(*a);
	while (len_a-- > 3)
		pb(a, b);
	swap_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_pos(*a);
	min = find_min(*a);
	if (min->above_median)
	{
		while (*a != min)
			ra(a);
	}
	else
	{
		while (*a != min)
			rra(a);
	}
}
