/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:56:32 by ncollie           #+#    #+#             */
/*   Updated: 2018/11/23 17:56:50 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		n;
	int		j;
	char	*result;
	char	temp;

	n = 0;
	j = 0;
	if (!f || !s)
		return (NULL);
	if (!(result = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[n])
	{
		if ((temp = f(n, s[n])))
			result[j++] = temp;
		n++;
	}
	result[j] = '\0';
	return (result);
}
