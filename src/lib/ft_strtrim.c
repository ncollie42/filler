/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:41:50 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/06 21:04:58 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

char		*ft_strtrim(char const *s)
{
	int		n;
	int		m;
	char	*temp;

	if (!s)
		return (NULL);
	n = 0;
	m = ft_strlen(s);
	while (s[n] && ft_isspace(s[n]))
		n++;
	while (m > 0 && ft_isspace(s[m - 1]))
		m--;
	if (m < n)
		temp = ft_strdup("");
	else
		temp = ft_strndup(s + n, (m - n));
	return (temp);
}
