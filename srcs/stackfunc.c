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
	elem->next = elem;
	elem->prev = elem;
	return (elem);
}

void	add_end(t_stack **start, t_stack *elem)
{
	if (!(*start))
		*start = elem;
	else
	{
		elem->next = *start;
		elem->prev = (*start)->prev;
		(*start)->prev->next = elem;
		(*start)->prev = elem;
	}
}

	// 	    ======================
	//      |                    |
	// 		1 <==> 2 <==> 3 <==> 4
	//      |             
	//      ======================

//void	create_stack()