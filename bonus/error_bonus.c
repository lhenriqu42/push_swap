/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:29:26 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/31 13:13:31 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_error(char *message)
{
	ft_printf_fd(STDERR_FILENO, C_ERROR "%s\n" C_BREAK, message);
}

void	handle_error(void)
{
	print_error("Error");
	exit(EXIT_FAILURE);
}

void	clear_and_exit(t_body *push_swap)
{
	if (push_swap->stack_a)
		free_stack(push_swap->stack_a);
	if (push_swap->stack_b)
		free_stack(push_swap->stack_b);
	exit(EXIT_SUCCESS);
}
