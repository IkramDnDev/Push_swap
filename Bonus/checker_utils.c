/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:25:32 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/20 16:21:07 by idahhan          ###   ########.fr       */
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
		// printf("Instruction lue : '%s'\n", line);
		tmp = instructions;
		instructions = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		if (!instructions)
			return (NULL);
		line = get_next_line(0);
	}
	// printf("Instructions finales reçues : '%s'\n", instructions);
	return (instructions);
}


static int	execute_instructions(t_stack_node **a, t_stack_node **b, char *instr)
{
	// printf("🔹 Avant l'exécution :\n");
	// print_stack(*a);
    // printf("-------\n");
	// print_stack(*b);
	// printf("➡️  Exécution : %s\n", instr);

	if (!ft_strncmp(instr, "sa", ft_strlen("sa")))
		sa(a, true);
	else if (!ft_strncmp(instr, "sb", ft_strlen("sb")))
		sb(b, true);
	else if (!ft_strncmp(instr, "ss", ft_strlen("ss")))
		ss(a, b, true);
	else if (!ft_strncmp(instr, "ra", ft_strlen("ra")))
		ra(a, true);
	else if (!ft_strncmp(instr, "rb", ft_strlen("rb")))
		rb(b, true);
	else if (!ft_strncmp(instr, "rr", ft_strlen("rr")))
		rr(a, b, true);
	else if (!ft_strncmp(instr, "rra", ft_strlen("rra")))
		rra(a, true);
	else if (!ft_strncmp(instr, "rrb", ft_strlen("rrb")))
		rrb(b, true);
	else if (!ft_strncmp(instr, "rrr", ft_strlen("rrr")))
		rrr(a, b, true);
	else if (!ft_strncmp(instr, "pa", ft_strlen("pa")))
		pa(b, a, true);
	else if (!ft_strncmp(instr, "pb", ft_strlen("pb")))
		pb(a, b, true);
	else
		return (0);
	// printf("✅ Après l'exécution :\n");
	// print_stack(*a);
    // printf("-------\n");
	// print_stack(*b);
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
