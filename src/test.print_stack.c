/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.print_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:36:13 by danbarbo          #+#    #+#             */
/*   Updated: 2025/01/30 11:20:59 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack()
{
	t_stack	*aux;
	t_stack *a = get_body()->stack_a;
	t_stack *b = get_body()->stack_b;
	update_positions(get_body()->stack_a);
	update_positions(get_body()->stack_b);
	aux = a;
	fprintf(stderr, "\n\n");
	fprintf(stderr, "I----------I\n");
	fprintf(stderr, "I stack a: I\n");
	fprintf(stderr, "I-------I--I-----------I---------------I--------I--------I----------------I\n");
	fprintf(stderr, "I value I sorted index I current index I cost_a I cost_b I      next      I\n");
	fprintf(stderr, "I-------I--------------I---------------I--------I--------I----------------I\n");
	while (aux)
	{
		fprintf(stderr, "I %5d I %12d I %13d I %6d I %6d I %14p I\n", aux->n, aux->sorted_position, aux->position, aux->cost_a, aux->cost_b, aux->down);
		aux = aux->down;
	}
	fprintf(stderr, "I-------I--------------I---------------I--------I--------I----------------I\n\n");
	aux = b;
	fprintf(stderr, "I----------I\n");
	fprintf(stderr, "I stack b: I\n");
	fprintf(stderr, "I-------I--I-----------I---------------I--------I--------I----------------I\n");
	fprintf(stderr, "I value I sorted index I current index I cost_a I cost_b I      next      I\n");
	fprintf(stderr, "I-------I--------------I---------------I--------I--------I----------------I\n");
	while (aux)
	{
		fprintf(stderr, "I %5d I %12d I %13d I %6d I %6d I %14p I\n", aux->n, aux->sorted_position, aux->position, aux->cost_a, aux->cost_b, aux->down);
		aux = aux->down;
	}
	fprintf(stderr, "I-------I--------------I---------------I--------I--------I----------------I\n");
	fflush(stderr);
}
