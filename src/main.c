/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:12:32 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/23 11:35:11 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_body *ps);

int	main(int argc, char *argv[])
{
	t_body *push_swap;

	if(argc == 1)
		return (1);
	ft_validate_args(argv);
	ft_init_numbers(argv);
	push_swap = get_body();
	if (!is_ordered(push_swap->stack_a))
	{
		// if (push_swap->length_a <= 10)
			// small_sort(push_swap);
		sort(push_swap);
		// else
			// big_sort(push_swap);
	}
	clear_and_exit(push_swap);
}
