/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:05:37 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/08 15:10:22 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alst && *alst)
	{
		temp = *alst;
		del(temp->content, temp->content_size);
		*alst = temp->next;
		free(temp);
		temp = NULL;
	}
}
