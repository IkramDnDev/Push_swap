/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:13:50 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/05 17:47:20 by idahhan          ###   ########.fr       */
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

int						check_arguments(int ac, char **av);
long					ft_atol(const char *str);
t_stack_node			*init_stack(char **av);
void					print_stack(t_stack_node *stack);
void					ft_free_split(char **split);
void					free_stack(t_stack_node **stack);
char					**concatinate_args(int ac, char **av);
//
void					print_error(int ac, char **av);
#endif