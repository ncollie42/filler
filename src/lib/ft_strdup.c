/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 23:16:34 by ncollie           #+#    #+#             */
/*   Updated: 2018/10/30 17:05:33 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*dup;

	length = ft_strlen((char *)s1);
	dup = (char *)malloc(sizeof(char) * (length + 1));
	if (dup == NULL)
		return (dup);
	ft_strcpy(dup, s1);
	return (dup);
}
