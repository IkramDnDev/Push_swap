/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatinate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:37:31 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/18 16:52:48 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

static int	is_empty_str(const char *str)
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
