/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:28:55 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/03 15:29:09 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t i;
	size_t m;

	i = 0;
	m = 0;
	while (s1[i])
		i++;
	while (s2[m] && n--)
		s1[i++] = s2[m++];
	s1[i] = '\0';
	return (s1);
}
