/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:30:24 by lnagy             #+#    #+#             */
/*   Updated: 2016/10/18 17:30:25 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tree	*new_leaf(int op)
{
	t_tree	*leaf;

	leaf = try(sizeof(t_tree));
	leaf->op = op;
	leaf->calc = 1;
	return (leaf);
}

t_tree	*climb_tree(t_tree *root, t_env *e)
{
	int		i;
	t_tree	*stock;

	i = 0;
	if (root->op != -1)
		if (!e->ops[root->op].f(&e->a, &e->b))
			return (NULL);
	if (root->calc)
	{
		if (!e->b && is_sorted(e->a))
			return (root);
		root->calc = 0;
		while (i < 11)
		{
			root->next[i] = (root->op == -1 || i != e->ops[root->op].rev_op) ?
			new_leaf(i) : NULL;
			i++;
		}
	}
	else
	{
		while (i < 11)
		{
			if (root->next[i])
				if ((stock = climb_tree(root->next[i], e)))
					return (stock);
			i++;
		}
	}
	if (root->op != -1)
		e->ops[root->op].rev(&e->a, &e->b);
	return (NULL);
}