/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:50:35 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/22 16:37:02 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	update_positions(t_stack *stack)
{
	int	i;
	
	i = 0;
	while(stack)
	{
		stack->position = i;
		stack = stack->down;
		i++;
	}
}

void	ft_init_numbers(char *argv[])
{
	t_body	*body;
	int		value;
	int		i;

	i = 1;
	body = get_body();
	while(argv[i])
	{
		value = ft_atoi(argv[i]);
		link_node(&(body->stack_a), value);
		i++;
	}
	body->length_a = stack_len(body->stack_a);
	update_positions(body->stack_a);
}