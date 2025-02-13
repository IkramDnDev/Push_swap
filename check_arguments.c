/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:13:38 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/13 17:22:46 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

static int	ft_overflow(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

static long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > (LONG_MAX - (str[i] - '0')) / 10)
			return (ft_overflow(sign));
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

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

	if (!av)
		return (0);
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

int	check_arguments(int ac, char **av)
{
	int	i;

	if (!av)
		write(2, "Error\n", 7);
	i = 0;
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
