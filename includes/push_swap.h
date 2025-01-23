/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:12:57 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/23 14:47:38 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"

// COLORS
# define C_SUCCESS "\033[32;3m"
# define C_ERROR "\033[31;1m"
# define C_BREAK "\033[0m"


// COMMANDS
typedef enum e_push
{
	pa,
	pb
}	t_push;

typedef enum e_swap
{
	sa,
	sb,
	ss
}	t_swap;

typedef enum e_rotate
{
	ra,
	rb,
	rr
}	t_rotate;

typedef enum e_rev_rotate
{
	rra,
	rrb,
	rrr
}	t_rev_rotate;

// BOOLEAN
typedef enum e_bool
{
	false,
	true
}	t_bool;


// STRUCTS
typedef struct s_stack
{
	int				n;
	int				position;
	struct s_stack	*up;
	struct s_stack	*down;
}					t_stack;

typedef struct s_body
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	length_a;
	size_t	length_b;
}			t_body;

void		handle_error(void);
t_stack	*get_last_node(t_stack *node);
void		clear_and_exit(t_body *push_swap);
void		ft_init_numbers(char *argv[]);
void		ft_validate_args(char *argv[]);
void		link_node(t_stack **stack, int value);
void		free_stack(t_stack *stack);
t_bool		is_ordered(t_stack *stack);
size_t		stack_len(t_stack *node);

void	small_sort(t_body *ps);
void	push(t_push type);
void	swap(t_swap type);
void	rotate(t_rotate type);
void	rev_rotate(t_rev_rotate type);
void	update_positions(t_stack *stack);

t_body		*get_body();

#endif