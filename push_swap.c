/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:13:45 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/05 19:24:30 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

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
	int				i;

	i = 0;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2 && !av[1][0])
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	else
		argv = concatinate_args(ac, av);
	if (!check_arguments(ac, argv))
		return (1);
	a = init_stack(argv);
	print_stack(a);
	free_stack(&a);
	ft_free_split(argv);
	return (0);
}

void	print_error(int ac, char **av)
{
	if (av[1][0] != '\0' && ac == 2)
		ft_free_split(av);
	else if (av[1][0] == '\0')
		exit(1);
}
