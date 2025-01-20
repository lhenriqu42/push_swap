/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:29:26 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/20 16:58:38 by lhenriqu         ###   ########.fr       */
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
