/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:24:23 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/20 12:07:19 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*top;

	if (!src || !*src)
		return ;
	top = *src;
	*src = top->next;
	if (*src)
		(*src)->prev = NULL;
	top->next = *dest;
	if (*dest)
		(*dest)->prev = top;
	*dest = top;
}

void	pa(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
