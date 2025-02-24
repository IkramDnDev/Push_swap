/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:05:55 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/24 16:36:14 by idahhan          ###   ########.fr       */
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
void					sa(t_stack_node **a, bool checker);
void					sb(t_stack_node **b, bool checker);
void					ss(t_stack_node **a, t_stack_node **b, bool checker);
// rotate
void					ra(t_stack_node **a, bool checker);
void					rb(t_stack_node **b, bool checker);
void					rr(t_stack_node **a, t_stack_node **b, bool checker);
// push
void					pa(t_stack_node **a, t_stack_node **b, bool checker);
void					pb(t_stack_node **b, t_stack_node **a, bool checker);
// rotate_reverse
void					rra(t_stack_node **a, bool checker);
void					rrb(t_stack_node **b, bool checker);
void					rrr(t_stack_node **a, t_stack_node **b, bool checker);

#endif