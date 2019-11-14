/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:05:11 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/06 18:01:06 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *found;
	char *temp;

	found = NULL;
	if (c == '\0')
		return (ft_strchr(s, c));
	while ((temp = ft_strchr(s, c)))
	{
		found = temp;
		s = temp + 1;
	}
	return (found);
}
