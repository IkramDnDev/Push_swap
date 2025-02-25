/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:25:32 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/24 17:00:08 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "checker.h"

void	check_result(t_stack_node *a, t_stack_node *b)
{
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static char	*read_instructions(void)
{
	char	*instructions;
	char	*line;
	char	*tmp;

	instructions = ft_strdup("");
	if (!instructions)
		return (NULL);
	line = get_next_line(0);
	while (line)
	{
		tmp = instructions;
		instructions = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		if (!instructions)
			return (NULL);
		line = get_next_line(0);
	}
	return (instructions);
}

static int	execute_instructions(t_stack_node **a, t_stack_node **b,
		char *instr)
{
	if (!ft_strncmp(instr, "sa", ft_strlen(instr)))
		sa(a);
	else if (!ft_strncmp(instr, "sb", ft_strlen(instr)))
		sb(b);
	else if (!ft_strncmp(instr, "ss", ft_strlen(instr)))
		ss(a, b);
	else if (!ft_strncmp(instr, "ra", ft_strlen(instr)))
		ra(a);
	else if (!ft_strncmp(instr, "rb", ft_strlen(instr)))
		rb(b);
	else if (!ft_strncmp(instr, "rr", ft_strlen(instr)))
		rr(a, b);
	else if (!ft_strncmp(instr, "rra", ft_strlen(instr)))
		rra(a);
	else if (!ft_strncmp(instr, "rrb", ft_strlen(instr)))
		rrb(b);
	else if (!ft_strncmp(instr, "rrr", ft_strlen(instr)))
		rrr(a, b);
	else if (!ft_strncmp(instr, "pa", ft_strlen(instr)))
		pa(b, a);
	else if (!ft_strncmp(instr, "pb", ft_strlen(instr)))
		pb(a, b);
	else
		return (0);
	return (1);
}

void	read_execute(t_stack_node **a, t_stack_node **b)
{
	char	*instructions;
	char	**lines;
	int		i;

	instructions = read_instructions();
	if (!instructions)
		return ;
	lines = ft_split(instructions, '\n');
	free(instructions);
	if (!lines)
		return ;
	i = 0;
	while (lines[i])
	{
		if (!execute_instructions(a, b, lines[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		free(lines[i]);
		i++;
	}
	free(lines);
}
