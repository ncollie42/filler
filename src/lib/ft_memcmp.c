/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:42:08 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/02 18:49:21 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int m;

	m = 0;
	while (n)
	{
		if (((char *)s1)[m] != ((char *)s2)[m])
			return (((unsigned char *)s1)[m] - ((unsigned char *)s2)[m]);
		n--;
		m++;
	}
	return (0);
}
