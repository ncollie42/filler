/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:31:02 by ncollie           #+#    #+#             */
/*   Updated: 2019/11/19 23:26:14 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_functions.h"

t_block	update_piece(t_block piece, t_dimentions d)
{
	int		yy;
	t_block	new;
	int		ofst;
	int		p_width;

	p_width = piece.dimen.width;
	ofst = 0;
	new = new_block(d);
	yy = -1;
	while (++yy < d.height)
	{
		ft_memmove(new.body + ofst, piece.body + (yy * p_width), d.width);
		ofst += d.width;
	}
	free(piece.body);
	return (new);
}

t_block	trim_piece(t_block piece)
{
	int				yy;
	int				xx;
	int				index;
	t_dimentions	d;

	d = (t_dimentions){0, 0};
	yy = -1;
	while (++yy < piece.dimen.height)
	{
		xx = -1;
		while (++xx < piece.dimen.width)
		{
			index = POS(xx, yy, piece.dimen.width);
			if (piece.body[index] == '*')
			{
				if (xx + 1 > d.width)
					d.width = xx + 1;
				if (yy + 1 > d.height)
					d.height = yy + 1;
			}
		}
	}
	if (piece.dimen.width != d.width || piece.dimen.height != d.height)
		piece = update_piece(piece, d);
	return (piece);
}
