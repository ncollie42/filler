/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:00:10 by ncollie           #+#    #+#             */
/*   Updated: 2019/11/18 22:24:37 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_functions.h"

void	gen_heat_map(block map, players p)
{
	block		visited_map;
	queue		*q1;
	queue		*q2;
	groupedMaps	maps;

	q1 = initQueue();
	q2 = initQueue();
	visited_map = newBlock(map.dimen);
	maps.map = map;
	maps.visited = visited_map;
	initQueFromMap(map, q1, visited_map, p);
	BFS_HeatMap(maps, q1, q2, 2);
	free(visited_map.body);
	free(q1);
	free(q2);
}

int		main(void)
{
	block		map;
	block		piece;
	players		p;
	cordinate	cord;

	p = setPlayers();
	while (1)
	{
		map = getBlock(MAP);
		piece = getBlock(PIECE);
		piece = trimPiece(piece);
		genHeatMap(map, p);
		printPieceHiddenF(map);
		cord = getBestCordinate(map, piece);
		freeBlocks(map.body, piece.body);
		printPoint(cord.x, cord.y);
	}
}
