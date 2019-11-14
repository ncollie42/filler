/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 20:54:25 by ncollie           #+#    #+#             */
/*   Updated: 2018/11/14 13:22:45 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int		n;
	char	*end;

	end = dest + ft_strlen(dest);
	n = -1;
	while (src[++n])
		end[n] = src[n];
	end[n] = '\0';
	return (dest);
}
