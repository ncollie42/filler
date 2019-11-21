/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_structs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:17:20 by ncollie           #+#    #+#             */
/*   Updated: 2019/11/19 23:28:52 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_STRUCTS_H
# define H_STRUCTS_H

/*
** for norm
*/
typedef struct	s_array_hold
{
	int	map_index;
	int	piece_index;
}				t_array_hold;

typedef struct	s_player_score
{
	int	player;
	int	score;
}				t_player_score;

/*
** filler
*/
typedef struct	s_dimentions
{
	int	height;
	int	width;
}				t_dimentions;

typedef struct	s_block
{
	t_dimentions	dimen;
	char			*body;
}				t_block;

typedef struct	s_players
{
	char	enemy;
	char	us;
}				t_players;

/*
** queue
*/
typedef struct	s_cordinate
{
	int	x;
	int	y;
}				t_cordinate;

typedef struct	s_node
{
	t_cordinate		cord;
	struct s_node	*next;
}				t_node;

typedef struct	s_queue
{
	t_node	*first;
	t_node	*last;
}				t_queue;

typedef struct	s_bothmaps
{
	t_block	map;
	t_block	visited;
}				t_bothmaps;

/*
** special return
*/
typedef struct	s_responce
{
	bool	valid;
	int		score;
}				t_responce;

#endif
