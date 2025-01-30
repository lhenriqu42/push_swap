/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:33:16 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/30 13:38:06 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_body *ps, t_stack *temp)
{
	t_stack	*first;
	t_stack	*seccond;
	t_stack	*third;

	first = ps->stack_a;
	seccond = first->down;
	third = seccond->down;
	if (first->n > seccond->n && first->n > third->n)
	{
		rotate(ra);
		temp = seccond;
		seccond = third;
		third = first;
		first = temp;
	}
	if (seccond->n > first->n && seccond->n > third->n)
	{
		rev_rotate(rra);
		temp = seccond;
		seccond = first;
		first = third;
		third = temp;
	}
	if (first->n > seccond->n)
		swap(sa);
}

void	small_sort(t_body *ps)
{
	if (ps->size == 2)
		swap(sa);
	else if (ps->size == 3)
		sort_three(ps, NULL);
	else
		sort(ps);
}
