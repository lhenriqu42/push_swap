/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:12:32 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/31 13:42:26 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	verify_stack(t_body *ps, int argc)
{
	if (is_ordered(ps->stack_a)
		&& (stack_len(ps->stack_a) == (size_t)(argc - 1)))
		ft_printf(C_SUCCESS "OK\n" C_BREAK);
	else
		ft_printf(C_ERROR "KO\n" C_BREAK);
}

int	main(int argc, char *argv[])
{
	t_body	*ps;

	if (argc == 1)
		return (1);
	ft_validate_args(argv);
	ft_init_numbers(argv);
	ps = get_body();
	read_commands();
	verify_stack(ps, argc);
	clear_and_exit(ps);
}
