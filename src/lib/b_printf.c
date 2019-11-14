/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollie <ncollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:02:37 by ncollie           #+#    #+#             */
/*   Updated: 2018/12/06 20:40:15 by ncollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int		g_count = 0;

static char	*b_base(unsigned long num, int base)
{
	char		*ref;
	static char	buffer[15];
	char		*ptr;

	ref = "0123456789abcdef";
	ptr = &buffer[14];
	*ptr = '\0';
	if (!num)
		*ptr = '0';
	while (num)
	{
		*--ptr = ref[num % base];
		num /= base;
	}
	return (ptr);
}

static int	b_print(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
	{
		b_print("(null)");
		return (-1);
	}
	while (s[count])
		count++;
	write(1, s, count);
	g_count += count;
	return (count);
}

static void	b_putchar(int c)
{
	write(1, &c, 1);
	g_count++;
}

static void	ft_putnbr(int num)
{
	if (num == -2147483648)
		b_print("-2147483648");
	else
	{
		if (num < 0)
		{
			b_putchar('-');
			num = -num;
		}
		if (num >= 10)
			ft_putnbr(num / 10);
		b_putchar((num % 10) + '0');
	}
}

int			b_printf(const char *restrict fmt, ...)
{
	va_list			ap;

	g_count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			b_putchar(*fmt);
		else if (*++fmt == 'd' || *fmt == 'i' || *fmt == 'u')
			(*fmt != 'u') ? ft_putnbr(va_arg(ap, int)) : \
						b_print(b_base(va_arg(ap, unsigned int), 10));
		else if (*fmt == 'c' || *fmt == '%')
			(*fmt != '%') ? b_putchar((va_arg(ap, int))) : b_putchar('%');
		else if (*fmt == 'o' || *fmt == 'x')
			b_print(b_base(va_arg(ap, unsigned int), (*fmt == 'o') ? 8 : 16));
		else if (*fmt == 'p')
			b_print("0x") && b_print(b_base(va_arg(ap, unsigned long), 16));
		else if (*fmt == 's')
			b_print(va_arg(ap, char *));
		fmt++;
	}
	va_end(ap);
	return (g_count);
}
