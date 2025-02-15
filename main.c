/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:13:45 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/15 17:31:19 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

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

void	f(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**argv;

	atexit(f);
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
	sort_stack(&a, &b);
	free_stack(&a);
	ft_free_split(argv);
	return (0);
}
