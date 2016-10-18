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

// void	set_ops(t_env *e)
// {	
// 	static t_op		ops[11] = {{"sa", sa}, {"sb", sb}, {"ss", ss}, {"pa", pa},
// 		{"pb", pb}, {"ra", ra}, {"rb", rb}, {"rr", rr},
// 		{"rra", rra}, {"rrb", rrb}, {"rrr", rrr}};
// 	int				i;

// 	i = 0;
// 	while (i < 11)
// 	{
// 		e->ops[i] = ops[i];
// 		i++;
// 	}
// }

void	print_stack(t_stack *stack, int mode)
{
	t_stack		*last_elem;

	if (!stack)
		return ;
	last_elem = stack->prev;
	while (stack != last_elem)
	{
		if (mode)
			ft_printf("%p : %d\n", stack, stack->n);
		else
			ft_printf("%p : %s\n", stack, env(NULL)->ops[stack->n]);
		stack = stack->next;
	}
	if (mode)
		ft_printf("%p : %d\n", stack, stack->n);
	else
		ft_printf("%p : %s\n", stack, env(NULL)->ops[stack->n]);
}