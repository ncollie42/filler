/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:10:31 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/08 14:54:51 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*content_copy;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		content_copy = ft_memalloc(content_size);
		ft_memcpy(content_copy, content, content_size);
		*new = (t_list){.content = content_copy, .content_size = content_size,
		.next = NULL};
	}
	else
		*new = (t_list){ .content_size = 0};
	return (new);
}
