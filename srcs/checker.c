/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:30:24 by lnagy             #+#    #+#             */
/*   Updated: 2016/10/18 17:30:25 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_op(t_op *ops, char *line)
{
	int i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp(ops[i].op, line))
			return (i);
		i++;
	}
	free(line);
	die("ERROR\n", EXIT_FAILURE);
	return (-1);
}

void	get_ops(t_env *e)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		ft_printf("e : %p -- e->a : %p -- &e->a %p\n", e, e->a, &e->a);
		e->ops[get_op(e->ops, line)].f(&e->a, &e->b);
		free(line);
		print_stack(e->a, 1);
		ft_putchar('\n');
		print_stack(e->b, 1);
	}
}

int		main(int ac, char **av)
{
	t_env	e;

	env(&e);
	create_stack(av + 1, &e, ac - 1);
	print_stack(e.a, 1);
	set_ops(&e);
	get_ops(&e);
	ft_printf("%s\n", e.b || !is_sorted(e.a) ? "KO" : "OK");
	return (0);
}
