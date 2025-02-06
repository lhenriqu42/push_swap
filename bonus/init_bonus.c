/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:38:30 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/06 11:56:45 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**get_args(int argc, char *argv[])
{
	int		i;
	char	*line;
	char	**args;

	i = 0;
	line = ft_strdup("");
	while (i < argc)
	{
		line = ft_strjoin_with_free(line, argv[i++]);
		line = ft_strjoin_with_free(line, " ");
	}
	args = ft_split(line, ' ');
	free(line);
	return (args);
}

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
