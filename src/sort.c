/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:14:42 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/30 12:41:49 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lst_assign_cost(t_stack *stk_a, t_stack *stk_b)
{
	int		a_len;
	int		b_len;
	t_stack	*min_a;

	a_len = stack_len(stk_a);
	b_len = stack_len(stk_b);
	while (stk_b)
	{
		min_a = get_min_greater_than(stk_a, stk_b->sorted_position);
		if (min_a->position > a_len / 2)
			stk_b->cost_a = min_a->position - a_len;
		else
			stk_b->cost_a = min_a->position;
		if (stk_b->position > b_len / 2)
			stk_b->cost_b = stk_b->position - b_len;
		else
			stk_b->cost_b = stk_b->position;
		stk_b = stk_b->down;
	}
}

static void	choose_rotate(int i)
{
	if (i > 0)
		rotate(ra);
	else
		rev_rotate(rra);
}

static void	push_all_b(t_body *ps, int i, t_stack *node)
{
	while (ps->size > 3)
	{
		node = get_min_position(ps->stack_a, ps->key_nbr);
		if (!node)
			ps->key_nbr += ps->key_nbr_factor;
		else
		{
			i = node->position;
			if (i > ps->size / 2)
				i = i - ps->size;
			while (i != 0)
			{
				choose_rotate(i);
				if (i > 0)
					i--;
				else
					i++;
			}
			push(pb);
			ps->size--;
		}
	}
}

static void	sort_b(t_body *ps)
{
	int	size;

	size = stack_len(ps->stack_b);
	while (size)
	{
		update_positions(ps->stack_a);
		update_positions(ps->stack_b);
		lst_assign_cost(ps->stack_a, ps->stack_b);
		exec_cheapest_move(ps->stack_b);
		size--;
	}
}

void	sort(t_body *ps)
{
	push_all_b(ps, 0, NULL);
	sort_three(ps);
	sort_b(ps);
	rotate_until_sorted(ps);
}
