#include "push_swap.h"

void	update_positions(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->position = i;
		stack = stack->down;
		i++;
	}
}

static t_stack	*get_min_node(t_stack *stack, int n)
{
	t_stack	*min;

	min = NULL;
	while (stack)
	{
		if ((stack->n > n) && (!min || stack->n < min->n))
			min = stack;
		stack = stack->down;
	}
	return (min);
}

static void	assign_sorted_positions(t_stack *stack)
{
	t_stack	*min;
	int		i;
	int		last_min;

	i = 1;
	last_min = INT_MIN;
	min = stack;
	while (min)
	{
		min = get_min_node(stack, last_min);
		if(!min)
			break ;
		min->sorted_position = i++;
		last_min = min->n;
	}
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
	ps->length_a = stack_len(ps->stack_a);
	update_positions(ps->stack_a);
	assign_sorted_positions(ps->stack_a);

	// for (t_stack *s = ps->stack_a; s; s = s->down)
	// 	ft_printf("%i: %i\n", s->sorted_position, s->n);
}
