/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:12:57 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/20 14:32:02 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"

// COLORS
# define C_SUCCESS "\033[32;3m"
# define C_ERROR "\033[31;1m"
# define C_BREAK "\033[0m"

// ERRORS
# define E_INVALID_ARGS 1

void		handle_error(short code);

#endif