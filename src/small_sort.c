/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:33:16 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/29 10:48:58 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_few_elements(t_body *ps)
{
    sort(ps);
}
void	sort_three(t_body *ps)
{
    t_stack *first;
    t_stack *seccond;
    t_stack *third;

	first = ps->stack_a;
	seccond = first->down;
	third = seccond->down;
	if(first->n > seccond->n && first->n > third->n)
		rotate(ra);
	if(seccond->n > first->n && seccond->n > third->n)
		rev_rotate(rra);
	if(first->n > seccond->n)
		swap(sa);
}

void	small_sort(t_body *ps)
{
	if (ps->size == 2)
		swap(sa);
	else if (ps->size == 3)
		sort_three(ps);
	else
		sort_few_elements(ps);
}