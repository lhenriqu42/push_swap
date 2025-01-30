/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:12:57 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/30 15:55:47 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"

# include <limits.h>

// COLORS
# define C_SUCCESS "\033[32;3m"
# define C_ERROR "\033[31;1m"
# define C_BREAK "\033[0m"

// BOOLEAN
typedef enum e_bool
{
	false,
	true
}	t_bool;

// CMD PUSH
typedef enum e_push
{
	pa,
	pb
}	t_push;

// CMD SWAP 
typedef enum e_swap
{
	sa,
	sb,
	ss
}	t_swap;

// CMD ROTATE
typedef enum e_rotate
{
	ra,
	rb,
	rr
}	t_rotate;

// CMD REVERSE ROTATE
typedef enum e_rev_rotate
{
	rra,
	rrb,
	rrr
}	t_rev_rotate;

// MAIN STRUCTS
typedef struct s_stack
{
	int				n;
	int				position;
	int				cost_a;
	int				cost_b;
	int				sorted_position;
	struct s_stack	*up;
	struct s_stack	*down;
}					t_stack;

typedef struct s_body
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	int		key_nbr_factor;
	int		key_nbr;
}			t_body;

// UTILS FUNCTIONS
t_body		*get_body(void);
void		handle_error(void);
void		free_stack(t_stack *stack);
void		clear_and_exit(t_body *push_swap);

// STACK FUNCTIONS
size_t		stack_len(t_stack *node);
t_bool		is_ordered(t_stack *stack);
t_stack		*get_max_node(t_stack *stack);
t_stack		*get_last_node(t_stack *node);
t_stack		*get_cheapest_node(t_stack *stk_b);
t_stack		*get_min_node(t_stack *stack, long n);
t_stack		*get_min_position(t_stack *stack, int max);
t_stack		*get_min_greater_than(t_stack *stk_a, int position);
void		update_positions(t_stack *stack);
void		link_node(t_stack **stack, int value);

// SORT FUNCTIONS
void		sort(t_body *ps);
void		push(t_push type);
void		swap(t_swap type);
void		rotate(t_rotate type);
void		small_sort(t_body *ps);
void		rev_rotate(t_rev_rotate type);
void		rotate_until_sorted(t_body *ps);
void		exec_cheapest_move(t_stack *lst_b);
void		sort_three(t_body *ps, t_stack *temp);

// INIT FUNCITONS
void		ft_init_numbers(char *argv[]);
void		ft_validate_args(char *argv[]);

#endif