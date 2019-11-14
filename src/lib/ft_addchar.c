/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:10:08 by ncollie           #+#    #+#             */
/*   Updated: 2018/11/24 22:03:52 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addchar(char *string, char c)
{
	char	*temp;
	int		size;

	size = ft_strlen(string);
	temp = ft_strnew(size + 2);
	ft_strcpy(temp, string);
	temp[size] = c;
	return (temp);
}

/*
** this one doesn't free the src string, just malloc a new
** one and add the char at the end
*/
