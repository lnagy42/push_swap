/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnagy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:36:07 by lnagy             #+#    #+#             */
/*   Updated: 2016/10/18 17:36:27 by lnagy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_op
{
	char	op[4];
	int		(*f)(t_stack **a, t_stack **b);
}				t_op;

typedef struct s_env
{
	t_stack 	*a;
	t_stack 	*b;
	t_stack		*op;
	t_op		ops[11];
}				t_env;

void			add_end(t_stack **start, t_stack *elem);
void			add_head(t_stack **stack, t_stack *elem);
void			set_ops(t_env *e);
void			print_stack(t_stack *stack, int mode);
void			create_stack(char **arg, t_env *e, int ac);
void			*try(size_t size);
void			die(char *s, int exit_code);
t_env			*env(t_env *e);
int				sa(t_stack **a, t_stack **b);
int				sb(t_stack **a, t_stack **b);
int				ss(t_stack **a, t_stack **b);
int				pa(t_stack **a, t_stack **b);
int				pb(t_stack **a, t_stack **b);
int				ra(t_stack **a, t_stack **b);
int				rb(t_stack **a, t_stack **b);
int				rr(t_stack **a, t_stack **b);
int				rra(t_stack **a, t_stack **b);
int				rrb(t_stack **a, t_stack **b);
int				rrr(t_stack **a, t_stack **b);

#endif
