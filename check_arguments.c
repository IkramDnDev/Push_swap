/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:13:38 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/06 12:02:13 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

static int	is_valid_nbr(const char *nbr)
{
	int		i;
	long	nb;

	i = 0;
	if (!nbr[i])
		return (0);
	if (nbr[i] == '+' || nbr[i] == '-')
		i++;
	if (!nbr[i])
		return (0);
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	nb = ft_atol(nbr);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	return (1);
}

static int	check_doubles(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_empty_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

char	**concatinate_args(int ac, char **av)
{
	int		i;
	char	*res;
	char	*tmp;
	char	**argv;

	i = 0;
	while (++i < ac)
	{
		if (is_empty_str(av[i]))
			print_error(NULL, 1);
	}
	i = 0;
	res = ft_strdup("");
	while (++i < ac)
	{
		tmp = ft_strjoin(res, " ");
		free(res);
		res = ft_strjoin(tmp, av[i]);
		free(tmp);
		if (!res)
			return (NULL);
	}
	argv = ft_split(res, ' ');
	free(res);
	return (argv);
}

int	check_arguments(int ac, char **av)
{
	int	i;

	i = 0;
	if (!av)
		write(2, "Error\n", 7);
	while (av[i])
	{
		if (!is_valid_nbr(av[i]))
		{
			print_error(av, ac == 2);
			return (0);
		}
		i++;
	}
	if (check_doubles(av))
	{
		print_error(av, ac == 2);
		return (0);
	}
	return (1);
}
