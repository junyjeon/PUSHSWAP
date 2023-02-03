/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:34:12 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 04:22:25 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	in_b_sort_four(t_stack *s, t_stack *s2, int tmp)
{
	t_compare	c;

	pa(s2, s, 1);
	hard_coding(s2, s, 3, 'b');
	compare_init(s, &c);
	tmp = s2->top->val;
	if (tmp > c.first)
		pb(s, s2, 1);
	else if (c.first > tmp && tmp > c.second)
	{
		pb(s, s2, 1);
		sb(s, 1);
	}
	else if (c.second > tmp && tmp > c.third)
	{
		rrb(s, 1);
		pb(s, s2, 1);
		rb(s, 1);
		rb(s, 1);
	}
	else
	{
		pb(s, s2, 1);
		rb(s, 1);
	}
}

static void	in_a_sort_four(t_stack *s, t_stack *s2, int tmp)
{
	t_compare	c;

	pb(s, s2, 1);
	tmp = s2->top->val;
	hard_coding(s, s2, 3, 'a');
	compare_init(s, &c);
	if (tmp < c.first)
		pa(s, s2, 1);
	else if (c.first < tmp && tmp < c.second)
	{
		pa(s, s2, 1);
		sa(s, 1);
	}
	else if (c.second < tmp && tmp < c.third)
	{
		rra(s, 1);
		pa(s, s2, 1);
		ra(s, 1);
		ra(s, 1);
	}
	else
	{
		pa(s, s2, 1);
		ra(s, 1);
	}
}

void	sort_four(t_stack *s, t_stack *s2, char ch)
{
	if (ch == 'a')
		in_a_sort_four(s, s2, 0);
	else if (ch == 'b')
		in_b_sort_four(s, s2, 0);
}