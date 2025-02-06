/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:12:32 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/06 11:56:56 by lhenriqu         ###   ########.fr       */
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

static int	count_args(char **argv)
{
	int	len;

	len = 0;
	while (argv[len])
		len++;
	return (len);
}

int	main(int argc, char *argv[])
{
	t_body	*ps;
	int		new_argc;

	if (argc == 1)
		return (1);
	ps = get_body();
	ps->argv = get_args(argc, argv);
	new_argc = count_args(ps->argv);
	ft_validate_args(ps->argv);
	ft_init_numbers(ps->argv);
	read_commands();
	verify_stack(ps, new_argc);
	clear_and_exit(ps);
}
