/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:29:26 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/20 14:33:05 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_error(char *message)
{
    ft_printf_fd(2, C_ERROR "%s\n" C_BREAK, message);
}

void	handle_error(short code)
{
	if(code == E_INVALID_ARGS)
        print_error("Invalid args");
    exit(code);
}