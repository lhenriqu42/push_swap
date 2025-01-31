/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:54:20 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/31 12:12:41 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	exec_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*seccond;

	if (*stack == NULL || (*stack)->down == NULL)
		return ;
	first = *stack;
	seccond = (*stack)->down;
	if (seccond->down != NULL)
		seccond->down->up = first;
	first->down = seccond->down;
	seccond->up = NULL;
	seccond->down = first;
	first->up = seccond;
	*stack = seccond;
}

void	swap(t_swap type)
{
	t_body	*ps;

	ps = get_body();
	if (type == sa)
	{
		exec_swap(&ps->stack_a);
	}
	else if (type == sb)
	{
		exec_swap(&ps->stack_b);
	}
	else if (type == ss)
	{
		exec_swap(&ps->stack_a);
		exec_swap(&ps->stack_b);
	}
}
