/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:01:24 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/06 18:01:46 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <libft.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t len;

	j = 0;
	i = ft_strlen(dst);
	len = ft_strlen(src);
	len += (dstsize <= i) ? dstsize : i;
	while (dstsize > 0 && i + j < dstsize - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (dstsize != 0)
		dst[i + j] = '\0';
	return (len);
}
