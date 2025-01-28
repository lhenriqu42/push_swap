/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:12:32 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/28 13:01:55 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_body *ps);

int	main(int argc, char *argv[])
{
	t_body *ps;

	if(argc == 1)
		return (1);
	ft_validate_args(argv);
	ft_init_numbers(argv);
	ps = get_body();
	// check_nodes(ps->stack_a);
	if (!is_ordered(ps->stack_a))
	{
		// if (ps->length_a <= 10)
			// small_sort(ps);
		sort(ps);
		// else
			// big_sort(ps);
	}
	// check_nodes(ps->stack_a);
	clear_and_exit(ps);
}
