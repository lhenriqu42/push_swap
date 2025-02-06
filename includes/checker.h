/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:12:57 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/02/06 11:36:13 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libs/libft/libft.h"

# include <limits.h>

// COLORS
# define C_SUCCESS "\033[32;3m"
# define C_ERROR "\033[31;1m"
# define C_WHITE "\033[37;4m"
# define C_BLUE "\033[34;3m"
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
	char	**argv;
}			t_body;

// UTILS FUNCTIONS
t_body		*get_body(void);
void		handle_error(void);
void		print_error(char *message);
void		free_stack(t_stack *stack);
void		clear_and_exit(t_body *push_swap);

// STACK FUNCTIONS
size_t		stack_len(t_stack *node);
t_bool		is_ordered(t_stack *stack);
t_stack		*get_last_node(t_stack *node);
void		link_node(t_stack **stack, int value);

// SORT FUNCTIONS
void		push(t_push type);
void		swap(t_swap type);
void		rotate(t_rotate type);
void		rev_rotate(t_rev_rotate type);

// INIT FUNCITONS
void		ft_init_numbers(char *argv[]);
void		ft_validate_args(char *argv[]);
char		**get_args(int argc, char *argv[]);

// EXEC FUNCTIONS
void		read_commands(void);

#endif
