/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:56:47 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/12 17:43:06 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

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
