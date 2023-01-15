/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:14:19 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/15 21:13:38 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ranked(t_stack *a, int *arr, int size)
{
	t_info	*cur;
	int		i;
	int		j;

	cur = a->top;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (cur->val == arr[j])
				cur->rank = j;
		cur = cur->prev;
	}
	free(arr);
}
