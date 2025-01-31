/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:38:30 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/31 13:05:58 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_init_numbers(char *argv[])
{
	t_body	*ps;
	int		value;
	int		i;

	i = 1;
	ps = get_body();
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		link_node(&(ps->stack_a), value);
		i++;
	}
}
