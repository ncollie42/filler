/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:31:43 by ncollie           #+#    #+#             */
/*   Updated: 2019/11/19 23:31:49 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_functions.h"

t_dimentions	get_t_dimentions(void)
{
	char			*line;
	char			**split;
	t_dimentions	ret;

	line = gnl();
	split = ft_strsplit(line, ' ');
	if (split[0] == NULL)
		exit(EXIT_FAILURE);
	ret.height = ft_atoi(split[1]);
	ret.width = ft_atoi(split[2]);
	free_split_line(split);
	return (ret);
}

t_players		set_players(void)
{
	char		*line;
	char		**split;
	t_players	p;

	line = gnl();
	split = ft_strsplit(line, ' ');
	p.us = (split[2][1] == '1') ? 'o' : 'x';
	p.enemy = (split[2][1] == '2') ? 'o' : 'x';
	free_split_line(split);
	return (p);
}

t_block			get_block(int type)
{
	t_block	tmp;
	int		hh;
	char	*line;
	int		offset;

	offset = 0;
	tmp = new_block(get_t_dimentions());
	hh = tmp.dimen.height;
	if (type == MAP)
	{
		gnl();
	}
	while (hh--)
	{
		line = gnl();
		ft_memmove(tmp.body + offset, (line + type), tmp.dimen.width);
		offset += tmp.dimen.width;
	}
	return (tmp);
}
