/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:37:31 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/31 12:12:10 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	exec_push(t_stack **dst, t_stack **src)
{
	t_stack	*node;
	t_stack	*node_down;

	if (!*src)
		return ;
	node = *src;
	node_down = (*src)->down;
	if (!node_down)
		*src = NULL;
	else
	{
		node->down = NULL;
		node_down->up = NULL;
		*src = node_down;
	}
	if (!*dst)
		*dst = node;
	else
	{
		(*dst)->up = node;
		node->down = *dst;
		*dst = node;
	}
}

void	push(t_push type)
{
	t_body	*ps;

	ps = get_body();
	if (type == pa)
	{
		exec_push(&ps->stack_a, &ps->stack_b);
	}
	else if (type == pb)
	{
		exec_push(&ps->stack_b, &ps->stack_a);
	}
}
