/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:09:32 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/07 19:59:12 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*temp;
	int		n;
	int		m;

	if (!s || !f)
		return (NULL);
	if (!(temp = ft_strdup(s)))
		return (NULL);
	n = -1;
	m = -1;
	while (s[++n])
	{
		if (f(s[n]))
			temp[++m] = f(s[n]);
	}
	return (temp);
}
