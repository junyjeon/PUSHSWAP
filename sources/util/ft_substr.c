/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 05:02:18 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 00:29:49 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				i;
	unsigned int	s_len;
	char			*str;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	str = (char *)malloc(s_len + 1);
	if (!str)
		return (0);
	i = 0;
	while (len-- && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
