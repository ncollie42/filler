/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 22:13:07 by ncollie           #+#    #+#             */
/*   Updated: 2019/11/19 23:11:15 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_functions.h"

char	*gnl(void)
{
	static char	buf[256];
	int			k;
	char		c;

	c = 0;
	k = 0;
	while (read(0, &c, 1) > 0)
	{
		if (c == '\n' || k > 255)
			break ;
		buf[k++] = c;
	}
	buf[k] = '\0';
	return (buf);
}

void	free_split_line(char **split)
{
	int	ii;

	ii = -1;
	while (split[++ii])
		free(split[ii]);
	free(split);
}

void	free_blocks(char *map, char *piece)
{
	free(map);
	free(piece);
}

t_block	new_block(t_dimentions dimen)
{
	t_block tmp;

	tmp.dimen = dimen;
	tmp.body = malloc(sizeof(char) * tmp.dimen.height * tmp.dimen.width);
	ft_bzero(tmp.body, tmp.dimen.height * tmp.dimen.width);
	return (tmp);
}

void	print_point(int x, int y)
{
	char	*num1;
	char	*num2;

	num2 = ft_itoa(x);
	num1 = ft_itoa(y);
	write(1, num1, ft_strlen(num1));
	write(1, " ", 1);
	write(1, num2, ft_strlen(num2));
	write(1, "\n", 1);
	free(num1);
	free(num2);
}
