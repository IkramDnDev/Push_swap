/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:47:42 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/24 11:36:41 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "checker.h"

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

void	pa(t_stack_node **b, t_stack_node **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pb\n", 3);
}
