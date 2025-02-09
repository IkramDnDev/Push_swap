/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:56:47 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/09 17:08:09 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

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

void	swap_three(t_stack_node **stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack); // 2 1 3
	else if (first > second && second > third)
	{
		sa(stack); // 3 2 1
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack); // 3 1 2
	else if (first < second && second > third && first < third)
	{
		sa(stack); // 1 3 2
		ra(stack);
	}
	else if (first < second && second > third)
		rra(stack); // 2 3 1
}

void	sort_stack(t_stack_node **stack)
{
	int	len;

	if (is_sorted(*stack))
	{
		write(1, "stack is sorted !\n", 19);
		free_stack(stack);
		exit(0);
	}
	len = len_stack(*stack);
	if (len == 2)
	{
		sa(stack);
	}
	else if (len == 3)
		swap_three(stack);
	else
		printf("number of argument is more than 3\n");
}
