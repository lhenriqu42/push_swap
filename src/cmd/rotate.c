/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:03:42 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/30 12:37:47 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_printf("ra\n");
	}
	else if (type == rb)
	{
		exec_rotate(&ps->stack_b);
		ft_printf("rb\n");
	}
	else if (type == rr)
	{
		exec_rotate(&ps->stack_a);
		exec_rotate(&ps->stack_b);
		ft_printf("rr\n");
	}
	update_positions(ps->stack_a);
	update_positions(ps->stack_b);
}
