/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_price.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:38:17 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/18 15:47:29 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

static void	above_median(t_stack_node **b)
{
	if ((*b)->current_position > (*b)->target_node->current_position)
		(*b)->push_price = (*b)->target_node->current_position
			+ ((*b)->current_position - (*b)->target_node->current_position);
	else if ((*b)->current_position < (*b)->target_node->current_position)
		(*b)->push_price = (*b)->current_position
			+ ((*b)->target_node->current_position - (*b)->current_position);
	else
		(*b)->push_price = (*b)->current_position;
}

static void	under_median(t_stack_node **b, int len_a, int len_b)
{
	int	inder_a;
	int	inder_b;

	if (!(*b)->above_median && !(*b)->target_node->above_median)
	{
		inder_a = len_a - (*b)->target_node->current_position;
		inder_b = len_b - (*b)->current_position;
		if (inder_b > inder_a)
			(*b)->push_price = inder_a + (inder_b - inder_a);
		else if (inder_b < inder_a)
			(*b)->push_price = inder_b + (inder_a - inder_b);
		else
			(*b)->push_price = inder_b;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = len_stack(a);
	len_b = len_stack(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!b->above_median)
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		if (b->above_median && b->target_node->above_median)
			above_median(&b);
		else if (!b->above_median && !b->target_node->above_median)
			under_median(&b, len_a, len_b);
		b = b->next;
	}
}
