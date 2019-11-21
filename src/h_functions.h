/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_functions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:06:37 by ncollie           #+#    #+#             */
/*   Updated: 2019/11/19 23:41:33 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_FUNCTIONS_H
# define H_FUNCTIONS_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../Lib/42_lib/includes/libft.h"
# include <stdbool.h>
# define POS(x, y, width) ((x) + (y) * (width))
# define MAP 4
# define PIECE 0
# define ENEMY 1
# define PLAYER 0
# include "h_structs.h"

t_block		new_block(t_dimentions dimen);

/*
** extra
*/
char		*gnl();
void		free_split_line(char **split);
void		free_blocks(char *map, char *piece);

/*
** read
*/
t_players	set_players();
t_block		get_block(int type);

/*
** peice update
*/
t_block		trim_piece(t_block piece);

/*
** heatmap
*/

t_cordinate	get_best_cordinate(t_block map, t_block piece);
void		print_point(int x, int y);

t_cordinate	de_queue(t_queue *q);
void		add_queue(t_queue *q, t_cordinate cord);
bool		is_queue_empty(t_queue *q);
t_queue		*init_queue();
t_node		*new_node(int x, int y);
/*
** heatmap
*/
void		initque(t_block map, t_queue *q1, t_block visited, t_players p);
void		bfs_heat_map(t_bothmaps maps, t_queue *q1, t_queue *q2, int level);

#endif
