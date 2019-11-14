/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_char_ptr_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:50:33 by ncollie           #+#    #+#             */
/*   Updated: 2018/11/28 18:51:37 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** for  NULL terminated char **
** get the number of elemtns
*/

int		double_char_ptr_size(char **list)
{
	int n;

	n = -1;
	while (list[++n])
		;
	return (n);
}
