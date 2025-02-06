/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:29:26 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/06 11:35:44 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(char *message)
{
	ft_printf_fd(STDERR_FILENO, C_ERROR "%s\n" C_BREAK, message);
}

void	handle_error(void)
{
	print_error("Error");
	exit(EXIT_FAILURE);
}

void	clear_and_exit(t_body *ps)
{
	if (ps->stack_a)
		free_stack(ps->stack_a);
	if (ps->argv)
		ft_free_matrix(ps->argv);
	if (ps->stack_b)
		free_stack(ps->stack_b);
	exit(EXIT_SUCCESS);
}
