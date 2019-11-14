/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:28:49 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/06 17:59:49 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t n;

	n = 0;
	if (!(ft_strlen(needle)) || !(ft_strcmp(needle, "")))
		return ((char *)haystack);
	while (n < len && haystack[n])
	{
		if (haystack[n] == needle[0])
		{
			if (ft_strlen(needle) > (len - n))
				return (NULL);
			if (!ft_strncmp(&haystack[n], needle, ft_strlen(needle)))
				return ((char *)&(haystack[n]));
		}
		n++;
	}
	return (NULL);
}
