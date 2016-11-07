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

void	saw_tree(t_tree *root, int branch)
{
	if (!root)
		return ;
	if (branch != -1 && root->next[branch])
	{
		saw_tree(root->next[branch], -1);
		root->next[branch] = NULL;
	}
	else
	{
		branch = 0;
		while (branch < 11)
		{
			saw_tree(root->next[branch], -1);
			free(root->next[branch]);
			branch++;
		}
	}
}

t_tree	*climb_tree(t_tree *upper, t_tree *stage, t_env *e)
{
	int			i;
	t_tree		*stock;
	const int	index[11] = {-1, -1, 0, -1, -1, -1, -1, 1, -1, -1, 2};
	static int	(*op_f[3][4])(t_stack **a, t_stack **b) = {
		{NULL, &sb, &sa, NULL}, {NULL, &rrb, &rra, NULL}, {NULL, &rb, &ra, NULL}};

	if (stage->op != -1)
	{
		if ((i = e->ops[stage->op].f(&e->a, &e->b)))
		{
			if (i != -1 && i != 3)
				op_f[index[stage->op]][i](&e->a, &e->b);
			upper->next[stage->op] = NULL;
			free(stage);
			return (NULL);
		}
	}
	i = 0;
	if (stage->calc)
	{
		if (!e->b && is_sorted(e->a))
			return ((t_ulong)add_head(&e->op, new_elem(stage->op)) * 0 + stage);
		stage->calc = 0;
		while (i < 11)
		{
			stage->next[i] = (stage->op == -1 || i != e->ops[stage->op].rev_op) ?
			new_leaf(i) : NULL;
			if (stage->next[i])
				stage->next[i]->parent = stage;
			i++;
		}
	}
	else
	{
		while (i < 11)
		{
			if (stage->next[i])
				if ((stock = climb_tree(stage, stage->next[i], e)))
					return (stock + (stage->op != -1 ?
						(t_ulong)add_head(&e->op, new_elem(stage->op)) * 0 : 0));
			i++;
		}
	}
	if (stage->op != -1)
		e->ops[stage->op].rev(&e->a, &e->b);
	return (NULL);
}
