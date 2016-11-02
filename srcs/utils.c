/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:48:36 by lnagy             #+#    #+#             */
/*   Updated: 2016/10/18 15:48:43 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_env	*env(t_env *e)
{
	static t_env	*pe = NULL;

	if (e)
		pe = e;
	return (pe);
}

void	die(char *s, int exit_code)
{
	t_env *e;

	e = env(NULL);
	ft_printf("%s : %s\n", exit_code ? "Failure" : "Success", s);
	exit(exit_code);
}

void	*try(size_t size)
{
	void	*p;

	if ((p = ft_memalloc(size)) == NULL)
		die("Couldnt allocate memory", EXIT_FAILURE);
	return (p);
}

void	set_ops(t_env *e)
{	
	const t_op		ops[11] = {{"sa", sa, sa, 0}, {"sb", sb, sb, 1},
		{"ss", ss, ss, 2}, {"pa", pa, pb, 4}, {"pb", pb, pa, 3},
		{"ra", ra, rra, 8}, {"rb", rb, rrb, 9}, {"rr", rr, rrr, 10},
		{"rra", rra, ra, 5}, {"rrb", rrb, rb, 6}, {"rrr", rrr, rr, 7}};
	int				i;

	i = 0;
	while (i < 11)
	{
		e->ops[i] = ops[i];
		i++;
	}
}


void	print_op(int o)
{
	ft_printf("op : %s\n", env(NULL)->ops[o].op);
}

void	print_stack(t_stack *stack, int mode)
{
	t_stack		*last_elem;

	if (!stack)
		return ;
	last_elem = stack->prev;
	while (stack != last_elem)
	{
		if (mode)
			ft_printf("%d\n", stack->n);
		else
			ft_printf("%s\n", env(NULL)->ops[stack->n].op);
		stack = stack->next;
	}
	if (mode)
		ft_printf("%d\n", stack->n);
	else
		ft_printf("%s\n", env(NULL)->ops[stack->n].op);
}
