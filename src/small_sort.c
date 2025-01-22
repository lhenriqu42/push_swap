/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:33:16 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/22 16:42:59 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_few_elements(t_body *ps)
{
    (void)ps;
}
void	sort_three(t_body *ps)
{
    (void)ps;
}

void	small_sort(t_body *ps)
{
	if (ps->length_a == 2)
		swap(sa);
	else if (ps->length_a == 3)
		sort_three(ps);
	else
		sort_few_elements(ps);
}