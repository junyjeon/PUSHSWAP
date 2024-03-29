/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:37:25 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 23:56:40 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_error(char *str, int flag)
{
	int	ar_len;

	if (flag)
	{
		ar_len = ft_strlen(str);
		write(2, str, ar_len + 1);
		exit(1);
	}
	else
		exit(0);
}
