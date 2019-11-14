/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:42:17 by ncollie           #+#    #+#             */
/*   Updated: 2018/11/05 17:39:13 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define HAS_NEWLINE_CHAR ((here) = (ft_strchr(hash[fd],'\n')))
#define SET_LINE *line = ft_strdup(hash[fd])
#define NEW_LINE_AT_END (here - hash[fd] == length - 1)
#define IF_AT_END ((!here) || NEW_LINE_AT_END)
#define FREE_FD_LINE_IN_HASH free(hash[fd])
#define SET_NULL_CHAR (*here) = ('\0')
#define NOTHING_TO_READ read_amount == 0 && (hash[fd] == NULL || !*hash[fd])

int		return_line(const int fd, char **line, char **hash)
{
	char	*here;
	int		length;
	char	*temp;

	here = NULL;
	length = ft_strlen(hash[fd]);
	if (HAS_NEWLINE_CHAR)
		SET_NULL_CHAR;
	SET_LINE;
	temp = (IF_AT_END) ? NULL : ft_strdup(here + 1);
	FREE_FD_LINE_IN_HASH;
	hash[fd] = temp;
	return (1);
}

void	useless_function(int fd, char **other, char **hash)
{
	*other = malloc(sizeof(char));
	**other = '\0';
	hash[fd] = *other;
}

int		get_next_line(const int fd, char **line)
{
	static char	*hash[4864];
	char		buf[BUFF_SIZE + 1];
	int			read_amount;
	char		*temp;
	char		*other;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	while ((read_amount = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_amount] = '\0';
		if (!hash[fd])
			useless_function(fd, &other, hash);
		temp = ft_strjoin(hash[fd], buf);
		free(hash[fd]);
		hash[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (read_amount == -1 || (NOTHING_TO_READ))
		return (read_amount);
	return (return_line(fd, line, hash));
}
