/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:12:32 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/06 11:24:06 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_body	*ps;

	if (argc == 1)
		return (1);
	ps = get_body();
	ps->argv = get_args(argc, argv);
	ft_validate_args(ps->argv);
	ft_init_numbers(ps->argv);
	if (!is_ordered(ps->stack_a))
	{
		if (ps->size <= 3)
			small_sort(ps);
		else
			sort(ps);
	}
	clear_and_exit(ps);
}
