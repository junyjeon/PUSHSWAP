/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:51:26 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 01:56:16 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_stack *s)
{
	int	val;
	int	rank;

	if (s->size <= 1)
		return ;
	val = s->top->val;
	s->top->val = s->top->prev->val;
	s->top->prev->val = val;
	rank = s->top->rank;
	s->top->rank = s->top->prev->rank;
	s->top->prev->rank = rank;
}

void	ss(t_stack *a, t_stack *b, int flag)
{
	swap(a);
	swap(b);
	if (flag)
		write(1, "ss\n", 3);
}

void	sa(t_stack *a, int flag)
{
	swap(a);
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int flag)
{
	swap(b);
	if (flag)
		write(1, "sb\n", 3);
}
