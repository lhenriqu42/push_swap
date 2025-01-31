/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:03:42 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/31 12:12:24 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	exec_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*seccond;

	if (*stack == NULL || (*stack)->down == NULL)
		return ;
	last = get_last_node(*stack);
	seccond = (*stack)->down;
	seccond->up = NULL;
	(*stack)->down = NULL;
	(*stack)->up = last;
	last->down = *stack;
	*stack = seccond;
}

void	rotate(t_rotate type)
{
	t_body	*ps;

	ps = get_body();
	if (type == ra)
	{
		exec_rotate(&ps->stack_a);
	}
	else if (type == rb)
	{
		exec_rotate(&ps->stack_b);
	}
	else if (type == rr)
	{
		exec_rotate(&ps->stack_a);
		exec_rotate(&ps->stack_b);
	}
}
