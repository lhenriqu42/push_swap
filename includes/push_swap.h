/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:12:57 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/20 17:19:52 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"

// COLORS
# define C_SUCCESS "\033[32;3m"
# define C_ERROR "\033[31;1m"
# define C_BREAK "\033[0m"

typedef struct s_stack {
	int				n;
	int				position;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_body {
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t length_a;
	size_t length_b;
}			t_body;

void		handle_error(void);
void		ft_init_numbers(char *argv[]);
void		ft_validate_args(char *argv[]);
void		link_node(t_stack **stack, int value);

size_t		stack_len(t_stack *node);


t_body		*get_body();

#endif