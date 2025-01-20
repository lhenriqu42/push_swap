/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:01:29 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/20 17:12:19 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_last_node(t_stack *node)
{
	if (node == NULL)
		handle_error();
	while(node->next)
		node = node->next;
	return (node);
}

static t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (new_node == NULL)
		handle_error();
	new_node->n = value;
	return (new_node);
}

void	link_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = create_node(value);
	if (!*stack)
		*stack = new_node;
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}