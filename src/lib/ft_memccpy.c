/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:59:13 by ncollie           #+#    #+#             */
/*   Updated: 2018/11/24 21:28:59 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const \
		void *restrict src, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*destination;
	unsigned char	car;

	i = 0;
	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	car = (unsigned char)c;
	while (i < n)
	{
		destination[i] = source[i];
		if (source[i] == car)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
