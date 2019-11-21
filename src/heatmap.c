/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:59:51 by ncollie           #+#    #+#             */
/*   Updated: 2019/11/19 23:35:18 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_functions.h"

void		initque(t_block map, t_queue *q1, t_block visited, t_players p)
{
	int	yy;
	int	xx;
	int	index;

	yy = -1;
	while (++yy < map.dimen.height)
	{
		xx = -1;
		while (++xx < map.dimen.width)
		{
			index = POS(xx, yy, map.dimen.width);
			if (map.body[index] != '.')
			{
				if (ft_tolower(map.body[index]) == p.enemy)
				{
					add_queue(q1, (t_cordinate){xx, yy});
					map.body[index] = ENEMY;
				}
				else
					map.body[index] = PLAYER;
				visited.body[index] = true;
			}
		}
	}
}

static bool	check_bounds(t_cordinate cord, t_dimentions dimen)
{
	if (cord.x < 0)
		return (false);
	if (cord.x >= dimen.width)
		return (false);
	if (cord.y < 0)
		return (false);
	if (cord.y >= dimen.height)
		return (false);
	return (true);
}

void		set_point(t_bothmaps maps, t_cordinate cord, t_queue *q, int level)
{
	int	index;

	index = POS(cord.x, cord.y, maps.map.dimen.width);
	if (check_bounds(cord, maps.map.dimen) && !maps.visited.body[index])
	{
		maps.visited.body[index] = true;
		maps.map.body[index] = level;
		add_queue(q, cord);
	}
}

void		points(t_bothmaps maps, t_cordinate cord, t_queue *q, int level)
{
	set_point(maps, (t_cordinate){cord.x - 1, cord.y}, q, level);
	set_point(maps, (t_cordinate){cord.x - 1, cord.y + 1}, q, level);
	set_point(maps, (t_cordinate){cord.x - 1, cord.y - 1}, q, level);
	set_point(maps, (t_cordinate){cord.x, cord.y + 1}, q, level);
	set_point(maps, (t_cordinate){cord.x, cord.y - 1}, q, level);
	set_point(maps, (t_cordinate){cord.x + 1, cord.y}, q, level);
	set_point(maps, (t_cordinate){cord.x + 1, cord.y + 1}, q, level);
	set_point(maps, (t_cordinate){cord.x + 1, cord.y - 1}, q, level);
}

void		bfs_heat_map(t_bothmaps maps, t_queue *q1, t_queue *q2, int level)
{
	t_cordinate	cords;

	while (!is_queue_empty(q1))
	{
		cords = de_queue(q1);
		points(maps, cords, q2, level);
	}
	if (is_queue_empty(q2))
		return ;
	bfs_heat_map(maps, q2, q1, level + 1);
}
