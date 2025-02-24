/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:13:50 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/24 16:24:18 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	struct s_stack_node	*target_node;
}						t_stack_node;

t_stack_node			*init_stack(char **av);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*return_cheapest(t_stack_node *b);

void					ft_free_split(char **split);
void					free_stack(t_stack_node **stack);
void					print_error(char **av, int free_av);
void					sort_stack(t_stack_node **a, t_stack_node **b);
void					swap_three(t_stack_node **stack);
void					set_target_node(t_stack_node *a, t_stack_node *b);
void					set_pos(t_stack_node *stack);
void					set_price(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *b);
void					set_target_node(t_stack_node *a, t_stack_node *b);
void					init_nodes(t_stack_node *a, t_stack_node *b);
void					push_swap(t_stack_node **a, t_stack_node **b);

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