/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:26:37 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/28 11:48:58 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_duplication(char *argv[])
{
	int		number;
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			if (number == ft_atoi(argv[j]))
				handle_error();
			j++;
		}
		i++;
	}
}

static void ft_check_sintax(char *argv[])
{
	char *number;
	int	i;
	int	j;

	i = 1;
	while(argv[i])
	{
		number = argv[i];
		j = 0;
		if(!ft_isdigit(number[j]) && number[j] != '-' && number[j] != '+')
			handle_error();
		j++;
		while(number[j])
		{
			if(!ft_isdigit(number[j]))
				handle_error();
			j++;
		}
		i++;
	}
}

void	ft_validate_args(char *argv[])
{
	ft_check_sintax(argv);
	ft_check_duplication(argv);
}
void	check_nodes(t_stack *stack)
{
	int i = 0;
	t_stack *temp = NULL;

	ft_printf("Stack Content: \n");
	while(stack && i <= 15)
	{
		ft_printf("%i: %i\n", i, stack->n);
		i++;
		temp = stack;
		stack = stack->down;
	}
	// ft_printf("###################\n");
	while(temp && --i >= 0)
	{
		// ft_printf("%i: %i\n", i, temp->n);
		temp = temp->up;
	}
}
