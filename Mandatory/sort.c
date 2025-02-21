/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:56:47 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/18 16:53:12 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len;

	if (is_sorted(*a))
	{
		write(1, "a is sorted !\n", 15);
		free_stack(a);
		exit(0);
	}
	len = len_stack(*a);
	if (len == 2)
		sa(a);
	else if (len == 3)
		swap_three(a);
	else
	{
		push_swap(a, b);
	}
}
