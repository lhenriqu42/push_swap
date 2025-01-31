/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:55:55 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/31 13:40:26 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	clear_invalid_command(char *command)
{
	free(command);
	print_error("Error");
	clear_and_exit(get_body());
}

static void	exec_command(char *command)
{
	if (!ft_strncmp(command, "sa\n", 3))
		swap(sa);
	else if (!ft_strncmp(command, "sb\n", 3))
		swap(sb);
	else if (!ft_strncmp(command, "ss\n", 3))
		swap(ss);
	else if (!ft_strncmp(command, "pa\n", 3))
		push(pa);
	else if (!ft_strncmp(command, "pb\n", 3))
		push(pb);
	else if (!ft_strncmp(command, "ra\n", 3))
		rotate(ra);
	else if (!ft_strncmp(command, "rb\n", 3))
		rotate(rb);
	else if (!ft_strncmp(command, "rr\n", 3))
		rotate(rr);
	else if (!ft_strncmp(command, "rra\n", 4))
		rev_rotate(rra);
	else if (!ft_strncmp(command, "rrb\n", 4))
		rev_rotate(rrb);
	else if (!ft_strncmp(command, "rrr\n", 4))
		rev_rotate(rrr);
	else
		clear_invalid_command(command);
}

void	read_commands(void)
{
	size_t	counter;
	char	*command;

	counter = 1;
	while (true)
	{
		if (ft_checkw(0))
			ft_printf(C_BLUE "%ist command" C_BREAK ">", counter++);
		command = get_next_line(0);
		if (command == NULL)
			break ;
		exec_command(command);
		free(command);
	}
}
