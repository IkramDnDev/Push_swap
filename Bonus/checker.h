/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:05:55 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/24 17:00:25 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}						t_stack_node;

t_stack_node			*init_stack(char **av);
char					**concatinate_args(int ac, char **av);
char					*get_next_line(int fd);
int						check_arguments(int ac, char **av);
void					ft_free_split(char **split);
void					free_stack(t_stack_node **stack);
void					print_error(char **av, int free_av);
void					free_stack(t_stack_node **stack);
int						is_sorted(t_stack_node *stack);
void					check_result(t_stack_node *a, t_stack_node *b);
void					read_execute(t_stack_node **a, t_stack_node **b);

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