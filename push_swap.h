/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:13:50 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/09 16:03:44 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}						t_stack_node;

long					ft_atol(const char *str);

t_stack_node			*init_stack(char **av);

void					print_stack(t_stack_node *stack);
void					ft_free_split(char **split);
void					free_stack(t_stack_node **stack);
void					print_error(char **av, int free_av);
void					sort_stack(t_stack_node **stack);

char					**concatinate_args(int ac, char **av);

int						is_sorted(t_stack_node *stack);
int						len_stack(t_stack_node *stack);
int						check_arguments(int ac, char **av);
// swap
void					sa(t_stack_node **a);
void					sb(t_stack_node **b);
void					ss(t_stack_node **a, t_stack_node **b);
// rotate
void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rr(t_stack_node **a, t_stack_node **b);
// push
void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **b, t_stack_node **a);
// rotate_reverse
void					rra(t_stack_node **a);
void					rrb(t_stack_node **b);
void					rrr(t_stack_node **a, t_stack_node **b);
#endif