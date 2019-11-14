/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:32:12 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/02 19:17:56 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char *)s;
	if (!n)
		return (NULL);
	while ((--n) && *temp != (unsigned char)c)
		temp++;
	return ((*temp == (unsigned char)c) ? temp : NULL);
}
