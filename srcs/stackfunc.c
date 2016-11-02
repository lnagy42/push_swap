/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:44:59 by lnagy             #+#    #+#             */
/*   Updated: 2016/10/18 15:45:05 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_elem(int n)
{
	t_stack	*elem;

	elem = try(sizeof(t_stack));
	elem->n = n;
	elem->prev = elem;
	elem->next = elem;
	return (elem);
}

t_stack	*add_end(t_stack **start, t_stack *elem)
{
	if (!(*start))
		*start = elem;
	elem->next = *start;
	elem->prev = (*start)->prev;
	(*start)->prev->next = elem;
	(*start)->prev = elem;
	return (elem);
}

t_stack	*add_head(t_stack **stack, t_stack *elem)
{
	add_end(stack, elem);
	*stack = (*stack)->prev;
	return (elem);
}

	// 	    ======================
	//      |                    |
	// 		1 <==> 2 <==> 3 <==> 4
	//      |             
	//      ======================

int		is_sorted(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (0);
	last = stack->prev;
	if (stack == last)
		return (1);
	while (stack->next != last)
		if (stack->n > stack->next->n)
			return (0);
		else
			stack = stack->next;
	return (stack->n > last->n ? 0 : 1);
}

void	create_stack(char **arg, t_env *e, int ac)
{
	while (ac--)
	{
		add_end(&e->a, new_elem(ft_atoi(*arg)));
		arg++;
	}
}
