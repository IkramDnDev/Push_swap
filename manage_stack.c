/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:53:04 by idahhan           #+#    #+#             */
/*   Updated: 2025/02/08 16:25:43 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

static t_stack_node	*stack_new(int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

static void	stack_add_back(t_stack_node **stack, t_stack_node *new_node)
{
	t_stack_node	*tmp;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

t_stack_node	*init_stack(char **av)
{
	t_stack_node	*stack;
	int				value;
	int				i;

	stack = NULL;
	i = 0;
	while (av[i])
	{
		value = ft_atoi(av[i]);
		stack_add_back(&stack, stack_new(value));
		i++;
	}
	return (stack);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL;
}

void print_stack(t_stack_node *stack)
{
    int count = 0; // Compteur de sécurité
    while (stack)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
        
        count++;
        if (count > 100) // Si on dépasse 100 éléments, il y a une boucle infinie
        {
            printf("⚠ Boucle infinie détectée !\n");
            break;
        }
    }
}

