/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:10:10 by ncollie           #+#    #+#             */
/*   Updated: 2018/09/12 15:10:33 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *temp;

	temp = dst;
	while (len && *src)
	{
		*temp++ = *src++;
		len--;
	}
	while (len--)
		*temp++ = '\0';
	return (dst);
}
