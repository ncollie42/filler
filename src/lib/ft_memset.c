/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 20:27:28 by ncollie           #+#    #+#             */
/*   Updated: 2018/09/12 15:33:08 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *ptr, int value, size_t size)
{
	unsigned char	sub;
	char			*temp;
	size_t			count;

	count = 0;
	temp = ptr;
	sub = (unsigned char)value;
	while (size--)
		temp[count++] = sub;
	return (ptr);
}
