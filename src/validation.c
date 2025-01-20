/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:26:37 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/20 15:42:04 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_validate_args(char *argv[])
{
	char *number;
	int	i;
	int	j;

	i = 1;
	while(argv[i])
	{
		number = argv[i];
		j = 0;
		if(!ft_isdigit(number[j]) && number[j] != '-' && number[j] != '+')
			handle_error();
		j++;
		while(number[j])
		{
			if(!ft_isdigit(number[j]))
				handle_error();
			j++;
		}
		i++;
	}
}
