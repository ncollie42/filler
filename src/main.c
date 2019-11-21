/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:00:10 by ncollie           #+#    #+#             */
/*   Updated: 2019/11/19 23:41:03 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_functions.h"

void	gen_heat_map(t_block map, t_players p)
{
	t_block			visited_map;
	t_queue			*q1;
	t_queue			*q2;
	t_bothmaps		maps;

	q1 = init_queue();
	q2 = init_queue();
	visited_map = new_block(map.dimen);
	maps.map = map;
	maps.visited = visited_map;
	initque(map, q1, visited_map, p);
	bfs_heat_map(maps, q1, q2, 2);
	free(visited_map.body);
	free(q1);
	free(q2);
}

int		main(void)
{
	t_block		map;
	t_block		piece;
	t_players	p;
	t_cordinate	cord;

	p = set_players();
	while (1)
	{
		map = get_block(MAP);
		piece = get_block(PIECE);
		piece = trim_piece(piece);
		gen_heat_map(map, p);
		cord = get_best_cordinate(map, piece);
		free_blocks(map.body, piece.body);
		print_point(cord.x, cord.y);
	}
}
