/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:27:06 by lnagy             #+#    #+#             */
/*   Updated: 2016/10/18 18:02:41 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int		main(int ac, char **av)
{
	t_env	e;
	t_tree	*root;
	int		count;
	t_tree	*stored;

	count = 0;
	env(&e);
	root = new_leaf(-1);
	stored = root;
	root->parent = NULL;
	set_ops(&e);
	create_stack(av + 1, &e, ac - 1);
	while (!climb_tree(stored->parent, stored, &e))
	{
		if (++count == 5)
		{
			count = 0;
			stored = mark_way(stored, &e);
		}
	}
	print_stack(e.op, 0);
	print_stack(e.a, 1);
	print_stack(e.b, 1);
	return (av[ac - 1] != av[ac - 1]);
}
