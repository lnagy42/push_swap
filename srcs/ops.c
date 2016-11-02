/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:48:36 by lnagy             #+#    #+#             */
/*   Updated: 2016/10/18 15:48:43 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack **a, t_stack **b)
{
	(void)b;
	if (!*a || (*a)->next == *a)
		return (-1);
	(*a)->n ^= (*a)->next->n;
	(*a)->next->n ^= (*a)->n;
	(*a)->n ^= (*a)->next->n;
	return (0);
}


int	sb(t_stack **a, t_stack **b)
{
	(void)a;
	if (!*b || (*b)->next == *b)
		return (-1);
	(*b)->n ^= (*b)->next->n;
	(*b)->next->n ^= (*b)->n;
	(*b)->n ^= (*b)->next->n;
	return (0);
}

int ss(t_stack **a, t_stack **b)
{
	return ((sa(a, b) == -1) + 2 * (sb(a, b) == -1));
}
// 1 0 1 1 
// 1 1 0 0

// 0 1 1 1
// 1 1 0 0

// 1 0 1 1
// 0 1 1 1

// 1 1 0 0 ^ ca marche/swap sur les binaires des chiffres 

int	ra(t_stack **a, t_stack **b)
{
	(void)b;
	if (!*a)
		return (-1);
	*a = (*a)->next;
	return (0);
}

int	rb(t_stack **a, t_stack **b)
{
	(void)a;
	if (!*b)
		return (-1);
	*b = (*b)->next;
	return (0);
}

int	rr(t_stack **a, t_stack **b)
{
	return ((ra(a, b) == -1) + 2 * (rb(a, b) == -1));
}

int	rra(t_stack **a, t_stack **b)
{
	(void)b;
	if (!*a)
		return (-1);
	*a = (*a)->prev;
	return (0);
}

int	rrb(t_stack **a, t_stack **b)
{
	(void)a;
	if (!*b)
		return (-1);
	*b = (*b)->prev;
	return (0);
}

int	rrr(t_stack **a, t_stack **b)
{
	return ((rra(a, b) == -1) + 2 * (rrb(a, b) == -1));
}

int	pa(t_stack **a, t_stack **b)
{
	t_stack	*t;

	t = *b;
	if (!*b)
		return (-1);
	if (*b == (*b)->next)
		*b = NULL;
	else {
		(*b)->prev->next = (*b)->next;
		(*b)->next->prev = (*b)->prev;
		*b = (*b)->next;
	}
	add_head(a, t);
	return (0);
}

int	pb(t_stack **a, t_stack **b)
{
	t_stack	*t;

	t = *a;
	if (!*a)
		return (-1);
	if (*a == (*a)->next)
		*a = NULL;
	else {
		(*a)->prev->next = (*a)->next;
		(*a)->next->prev = (*a)->prev;
		*a = (*a)->next;
	}
	add_head(b, t);
	return (0);
}
