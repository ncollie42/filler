/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:42:37 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/08 17:25:25 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;
	t_list *result;
	t_list *current;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		if (!(result = f(lst)))
			return (NULL);
		if (!new_list)
			new_list = result;
		else
		{
			current = new_list;
			while (current->next)
				current = current->next;
			current->next = result;
		}
		result->next = NULL;
		lst = lst->next;
	}
	return (new_list);
}
