/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:38:33 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/06 19:39:22 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int			ft_atoi(const char *str)
{
	int				sign;
	unsigned int	index;
	unsigned long	num;

	num = 0;
	index = 0;
	sign = 1;
	while (skip_space(str[index]))
		index++;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	while (ft_isdigit(str[index]))
	{
		num = num * 10 + str[index] - '0';
		index++;
		if (num > __LONG_MAX__)
			return ((sign == 1) ? -1 : 0);
	}
	return (num * sign);
}
