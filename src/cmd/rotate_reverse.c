/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:24:15 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/22 15:45:46 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_rev_rotate(t_stack **stack)
{
	t_stack	*new_first;

	if (*stack == NULL || (*stack)->up == NULL)
		return ;
	new_first = get_last_node(*stack);
    new_first->up->down = NULL;
	new_first->up = NULL;
    new_first->down = *stack;
    (*stack)->up = new_first;
    *stack = new_first;
}

void rev_rotate(t_rev_rotate type)
{
    t_body  *ps;

	ps = get_body();
    if (type == rra)
	{
		exec_rev_rotate(&ps->stack_a);
		ft_printf("rra\n");
	}
	else if (type == rrb)
	{
		exec_rev_rotate(&ps->stack_b);
		ft_printf("rrb\n");
	}
	else if (type == rrr)
	{
		exec_rev_rotate(&ps->stack_a);
		exec_rev_rotate(&ps->stack_b);
		ft_printf("rrr\n");
	}
}
