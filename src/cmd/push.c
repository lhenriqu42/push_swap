/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:37:31 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/22 15:01:56 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_push(t_stack **dst, t_stack **src)
{
	t_stack	*node;
	t_stack	*node_down;

	if (*src == NULL)
		return ;
	node = *src;
	node_down = (*src)->down;
	if (node_down != NULL)
		(node_down)->up = NULL;
	if (*dst == NULL)
	{
		*dst = node;
		node->down = NULL;
	}
	else
	{
		node->down = *dst;
		(*dst)->up = node;
		*dst = node;
	}
}

void	push(t_push type)
{
	t_body  *ps;

	ps = get_body();
	if (type == pa)
	{
		exec_push(&ps->stack_a, &ps->stack_b);
		ft_printf("pa\n");
	}
	else if (type == pb)
	{
		exec_push(&ps->stack_b, &ps->stack_a);
		ft_printf("pb\n");
	}
}
