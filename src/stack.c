/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:01:29 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/29 17:02:02 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_until_sorted(t_body *ps)
{
	int size;
	int moves_to_sort;
	
	update_positions(ps->stack_a);
	moves_to_sort = get_min_position(ps->stack_a, 0)->position;
	size = stack_len(ps->stack_a);
	if (moves_to_sort > size / 2)
		moves_to_sort = moves_to_sort - size;
	while (moves_to_sort != 0)
	{
		if (moves_to_sort > 0)
		{
			rotate(ra);
			moves_to_sort--;
		}
		else
		{
			rev_rotate(rra);
			moves_to_sort++;
		}
	}
}

t_stack	*get_last_node(t_stack *node)
{
	if (node == NULL)
		handle_error();
	while(node->down)
		node = node->down;
	return (node);
}

static t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (new_node == NULL)
		handle_error();
	new_node->n = value;
	new_node->ID = new_node;
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
		last_node->down = new_node;
		new_node->up = last_node;
	}
}

t_bool	is_ordered(t_stack *stack)
{
	t_stack	*temp;

	if (stack == NULL)
		return (false);
	temp = stack;
	while (temp->down)
	{
		if (temp->n > temp->down->n)
			return (false);
		temp = temp->down;
	}
	return (true);
}
