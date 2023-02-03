/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stack_and_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:59 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/14 05:36:38 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parsing_stack_and_array(t_stack *a,  int argc, char **argv)
{
	t_info	*new;
	int		i;
	int		*arr;
	char	**split_str;
	char	*str;
	
	str = NULL;
	i = 0;
	while (++i < argc)
		str = ft_strjoin(str, argv[i]);
	split_str = ft_split(str, ' ');
	i = 0;
	while (split_str[i])
		i++;
	arr = malloc(sizeof(arr) * i);
	if (!arr)
		print_error("Memory allocation fail.\n");
	while (i--)
	{
		arr[i] = ft_atoi_ll(split_str[i]);
		new = ft_lstnew(arr[i]);
		push_back(a, new);
		free(split_str[i]);
	}
	free(split_str);
	return (arr);
}