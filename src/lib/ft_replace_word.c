/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:59:22 by ncollie           #+#    #+#             */
/*   Updated: 2018/11/26 15:04:27 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** replace old with new
** if new isn't in it, it will remove old from string
*/

char	*ft_replace_word(char *string, char *old, char *new_w)
{
	int		new_l;
	int		old_l;
	char	*new_string;
	char	*temp;

	if (!string || !old || !new_w)
		return (NULL);
	new_l = ft_strlen(new_w);
	old_l = ft_strlen(old);
	if ((temp = ft_strstr(string, old)))
	{
		new_string = malloc(sizeof(char) * (ft_strlen(string) +
					(new_l - old_l) + 1));
		ft_strncpy(new_string, string, (temp - string));
		ft_strncpy((new_string + (temp - string)), new_w, new_l);
		ft_strcpy((new_string + (temp - string) + new_l), temp + old_l);
		return (new_string);
	}
	else
		return (NULL);
}
