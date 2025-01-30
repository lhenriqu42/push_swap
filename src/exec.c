/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:39:27 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/30 12:38:15 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack *cheapest_node)
{
	while (cheapest_node->cost_a > 0 && cheapest_node->cost_b > 0)
	{
		rotate(rr);
		cheapest_node->cost_a--;
		cheapest_node->cost_b--;
	}
	while (cheapest_node->cost_a < 0 && cheapest_node->cost_b < 0)
	{
		rev_rotate(rrr);
		cheapest_node->cost_a++;
		cheapest_node->cost_b++;
	}
}

static void	rotate_a(t_stack *cheapest_node)
{
	while (cheapest_node->cost_a != 0)
	{
		if (cheapest_node->cost_a > 0)
		{
			rotate(ra);
			cheapest_node->cost_a--;
		}
		else
		{
			rev_rotate(rra);
			cheapest_node->cost_a++;
		}
	}
}

static void	rotate_b(t_stack *cheapest_node)
{
	while (cheapest_node->cost_b != 0)
	{
		if (cheapest_node->cost_b > 0)
		{
			rotate(rb);
			cheapest_node->cost_b--;
		}
		else
		{
			rev_rotate(rrb);
			cheapest_node->cost_b++;
		}
	}
}

void	exec_cheapest_move(t_stack *lst_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(lst_b);
	rotate_both(cheapest_node);
	rotate_a(cheapest_node);
	rotate_b(cheapest_node);
	push(pa);
}
