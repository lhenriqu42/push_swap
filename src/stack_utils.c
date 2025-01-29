/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:19:47 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/29 16:18:51 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_min_greater_than(t_stack *stk_a, int position)
{
	t_stack	*min;

	min = get_max_node(stk_a);
	if (position > min->sorted_position)
		return (get_min_position(stk_a, 0));
	while (stk_a)
	{
		if (stk_a->sorted_position > position
			&& stk_a->sorted_position < min->sorted_position)
			min = stk_a;
		stk_a = stk_a->down;
	}
	return (min);
}

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

t_stack	*get_max_node(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->n > max->n)
			max = stack;
		stack = stack->down;
	}
	return (max);
}

t_stack *get_min_position(t_stack *stack, int max)
{
    if (max == 0)
		return (get_min_node(stack, INT_MIN));
	while (stack)
	{
		if (stack->sorted_position <= max)
			return (stack);
		stack = stack->down;
	}
	return (NULL);
}