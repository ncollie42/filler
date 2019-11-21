/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:18:46 by ncollie           #+#    #+#             */
/*   Updated: 2019/11/19 23:36:05 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_functions.h"

static bool			check_bounds(t_block map, t_block piece, int x, int y)
{
	if ((x + piece.dimen.width) > map.dimen.width)
		return (false);
	if ((y + piece.dimen.height) > map.dimen.height)
		return (false);
	return (true);
}

t_array_hold		norm(t_cordinate p, t_cordinate m, t_block pi, t_block ma)
{
	t_array_hold tmp;

	tmp.piece_index = POS(p.x, p.y, pi.dimen.width);
	tmp.map_index = POS(m.x + p.x, m.y + p.y, ma.dimen.width);
	return (tmp);
}

t_responce			check_placement(t_block map, t_block piece, int x, int y)
{
	t_cordinate		p;
	t_array_hold	indexs;
	t_player_score	ps;

	p.y = -1;
	ps = (t_player_score){0, 0};
	while (++p.y < piece.dimen.height)
	{
		p.x = -1;
		while (++p.x < piece.dimen.width)
		{
			indexs = norm(p, (t_cordinate){x, y}, piece, map);
			if (piece.body[indexs.piece_index] == '*')
			{
				if (map.body[indexs.map_index] == ENEMY)
					return (t_responce){.valid = false, .score = 0};
				if (map.body[indexs.map_index] == PLAYER)
					ps.player++;
				ps.score += map.body[indexs.map_index];
			}
		}
	}
	if (ps.player == 1)
		return (t_responce){.valid = true, .score = ps.score};
	return (t_responce){.valid = false, .score = 0};
}

t_cordinate			get_best_cordinate(t_block map, t_block piece)
{
	t_cordinate			p;
	int					index;
	t_responce			rspn;
	t_cordinate			ret;
	int					best;

	best = INT32_MAX;
	ret = (t_cordinate){0, 0};
	p.y = -1;
	while (++p.y < map.dimen.height)
	{
		p.x = -1;
		while (++p.x < map.dimen.width)
		{
			index = POS(p.x, p.y, map.dimen.width);
			if (check_bounds(map, piece, p.x, p.y))
			{
				rspn = check_placement(map, piece, p.x, p.y);
				if (rspn.valid && (best > rspn.score) && (best = rspn.score))
					ret = (t_cordinate){p.x, p.y};
			}
		}
	}
	return (ret);
}
