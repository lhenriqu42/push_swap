/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:14:42 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/28 17:05:25 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_body *ps)
{
    size_t i;
    t_stack *check;
    t_stack *smallest;

   i = 0;
    while(i < ps->length_a)
    {
        check = ps->stack_a;
        smallest = ps->stack_a;
        while(check)
        {
            if(check->n < smallest->n)
                smallest = check;
            check = check->down;
        }
        while(smallest != ps->stack_a)
            rotate(ra);
        push(pb);
        i++;
    }
    i = 0;
    while(i < ps->length_a)
    {
        push(pa);
        i++;
    }
}
