/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:19:47 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/29 11:25:53 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_min_node(t_stack *stack, int n)
{
	t_stack	*min;

	min = NULL;
	while (stack)
	{
		if ((stack->n > n) && (!min || stack->n < min->n))
			min = stack;
		stack = stack->down;
	}
	return (min);
}

t_stack *get_min_position(t_stack *stack, int max)
{
    if (max == 0)
		return (get_min_node(stack, NULL));
	while (stack)
	{
		if (stack->sorted_position <= max)
			return (stack);
		stack = stack->down;
	}
	return (NULL);
}