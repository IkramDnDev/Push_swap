/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:55:52 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/24 16:37:33 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "checker.h"

void	print_error(char **av, int free_av)
{
	write(2, "Error\n", 7);
	if (free_av && av)
		ft_free_split(av);
	exit(1);
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**argv;

	argv = NULL;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2 && !av[1][0])
		print_error(NULL, 1);
	else
		argv = concatinate_args(ac, av);
	if (!check_arguments(ac, argv))
		return (1);
	a = init_stack(argv);
	read_execute(&a, &b);
	check_result(a, b);
	free_stack(&a);
	ft_free_split(argv);
	return (0);
}
