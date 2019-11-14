/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:19:10 by ncollie           #+#    #+#             */
/*   Updated: 2018/11/25 20:27:43 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (!(ft_strlen(needle)) || !(ft_strcmp(needle, "")))
		return ((char *)haystack);
	while (*haystack)
	{
		if ((*haystack) == needle[0])
		{
			if (!ft_strncmp(haystack, needle, ft_strlen(needle)))
				return ((char *)(haystack));
		}
		haystack++;
	}
	return (NULL);
}
