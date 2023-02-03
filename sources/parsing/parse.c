/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:59 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 04:48:35 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	arr_sort(int *arr, int size, int swap_cnt)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				swap_cnt++;
			}
		}
	}
	if (swap_cnt == 0)
		print_error("It's aligned.\n");
}

static void	check_overlap(int *arr, int size)
{
	int	i;

	if (1 == size)
		print_error("Arguments vector is one.\n");
	arr_sort(arr, size, 0);
	i = -1;
	while (++i < size - 1)
		if (arr[i] == arr[i + 1])
			print_error("Duplicate!\n");
}

static int	*make_list(t_stack *a, char **split_str, int i)
{
	t_info	*new;
	int		*arr;
	
	arr = malloc(sizeof(int) * i);
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

int	*parse(t_stack *a, int argc, char **argv)
{
	char	**split_str;
	char	*str;
	int		*arr;
	int		i;

	str = NULL;
	i = 0;
	while (++i < argc)
		str = ft_strjoin(str, argv[i]);
	split_str = ft_split(str, ' ');
	i = 0;
	while (split_str[i])
		i++;
	arr = make_list(a, split_str, i);
	check_overlap(arr, a->size);
	return (arr);
}
