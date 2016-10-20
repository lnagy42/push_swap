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

// while (get_next_line(0, &line))

int		main(int ac, char **av)
{
	t_env	e;

	env(&e);
	create_stack(av + 1, &e, ac - 1);
	print_stack(e.a, 1);
	set_ops(&e);
	return (0);
}
