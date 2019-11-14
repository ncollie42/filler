/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:17:24 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/02 15:19:16 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *source;
	char *temp;

	temp = (char *)dst;
	source = (char *)src;
	if (dst > src)
	{
		while (len)
		{
			*(temp + len - 1) = *(source + len - 1);
			len--;
		}
	}
	else
		ft_memcpy(temp, source, len);
	return (temp);
}
