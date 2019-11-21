/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:12:35 by ncollie           #+#    #+#             */
/*   Updated: 2019/11/19 23:22:19 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_functions.h"

t_queue		*init_queue(void)
{
	t_queue	*tmp;

	tmp = malloc(sizeof(t_queue));
	tmp->first = NULL;
	tmp->last = NULL;
	return (tmp);
}

bool		is_queue_empty(t_queue *q)
{
	return (!q->first);
}

void		add_queue(t_queue *q, t_cordinate cord)
{
	t_node	*new;

	new = new_node(cord.x, cord.y);
	if (is_queue_empty(q))
		q->first = new;
	else
		q->last->next = new;
	q->last = new;
}

t_cordinate	de_queue(t_queue *q)
{
	t_node		*tmp;
	t_cordinate	cord;

	tmp = q->first;
	cord = tmp->cord;
	q->first = q->first->next;
	if (is_queue_empty(q))
		q->last = NULL;
	free(tmp);
	return (cord);
}

t_node		*new_node(int x, int y)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	tmp->cord.x = x;
	tmp->cord.y = y;
	tmp->next = NULL;
	return (tmp);
}
