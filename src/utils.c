/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:44:16 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/30 12:47:09 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_body	*get_body(void)
{
	static t_body	body;

	return (&body);
}

size_t	stack_len(t_stack *node)
{
	size_t	len;

	len = 0;
	while (node)
	{
		len++;
		node = node->down;
	}
	return (len);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack->down;
		free(stack);
		stack = temp;
	}
}
