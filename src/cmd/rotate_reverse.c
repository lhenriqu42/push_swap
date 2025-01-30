/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:24:15 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/30 12:37:18 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_rev_rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;

	first_node = *stack;
	if (stack_len(first_node) < 1)
		return ;
	last_node = get_last_node(first_node);
	last_node->up->down = NULL;
	last_node->up = NULL;
	first_node->up = last_node;
	last_node->down = first_node;
	*stack = last_node;
}

void	rev_rotate(t_rev_rotate type)
{
	t_body	*ps;

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
	update_positions(ps->stack_a);
	update_positions(ps->stack_b);
}
