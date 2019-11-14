/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:30:23 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/07 19:58:47 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		temp;
	int		m;
	char	*result;
	int		neg;

	neg = (n < 0) ? 1 : 0;
	m = neg;
	temp = n;
	while (temp /= 10)
		m++;
	m++;
	if (!(result = ft_strnew(m)))
		return (NULL);
	result[--m] = (n < 0) ? -(n % 10) + '0' : (n % 10) + '0';
	while (n /= 10)
		result[--m] = (n < 0) ? -(n % 10) + '0' : (n % 10) + '0';
	if (neg)
		result[--m] = '-';
	return (result);
}
