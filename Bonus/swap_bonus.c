/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:44:06 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/24 11:36:07 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "checker.h"

void	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!stack || !*stack)
		return ;
	first = *stack;
	second = first->next;
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack_node **a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}
