/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_read_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:31:43 by ncollie           #+#    #+#             */
/*   Updated: 2019/11/18 22:52:05 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_functions.h"

dimentions	get_dimentions()
{
    char		*line;
    char		**split;
    dimentions	ret;

    line = gnl();
    split = ft_strsplit(line, ' ');
    if (split[0] == NULL)
        exit(EXIT_FAILURE);
    ret.height = ft_atoi(split[1]);
    ret.width = ft_atoi(split[2]);
    freeSplitLine(split);
    return ret;
}

players		setPlayers()
{
    char	*line;
    char	**split;
    players	p;

    line = gnl();
    split = ft_strsplit(line, ' ');
    p.us = (split[2][1] == '1') ? 'o' : 'x';
    p.enemy = (split[2][1] == '2') ? 'o' : 'x'; 
    freeSplitLine(split);
    return p;
}

block	getBlock(int type) {
    block   tmp;
    int     hh;
    char    *line;
    int     offset;

    offset = 0;
    tmp = newBlock(get_dimentions());
    hh = tmp.dimen.height;
    if (type == MAP) {
        gnl();
    }
    while(hh--) {
        line = gnl();
        ft_memmove(tmp.body + offset, (line + type), tmp.dimen.width);
        offset += tmp.dimen.width;
    }
    return tmp;
}
