/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyildiz <seyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:35:43 by seyildiz          #+#    #+#             */
/*   Updated: 2022/02/19 19:01:58 by seyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	p_count;

	p_count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[p_count])
		write(1, str + p_count++, 1);
	return (p_count);
}

int	ft_putbase(long double n, char c, int b)
{
	int		p_count;
	char	*base;

	p_count = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		p_count = 1;
	}
	if (n >= b)
		p_count += ft_putbase(n / b, c, b);
	p_count += write(1, &base[(unsigned long)n % b], 1);
	return (p_count);
}

int	ft_format(char c, va_list arg)
{
	int			p_count;

	p_count = 0;
	if (c == 'c')
		p_count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		p_count += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		p_count += ft_putbase(va_arg(arg, int), c, 10);
	else if (c == 'u')
		p_count += ft_putbase(va_arg(arg, unsigned int), c, 10);
	else if (c == 'x' || c == 'X')
		p_count += ft_putbase(va_arg(arg, unsigned int), c, 16);
	else if (c == 'p')
	{
		p_count += ft_putstr("0x");
		p_count += ft_putbase(va_arg(arg, unsigned long int), c, 16);
	}
	else if (c == '%')
		p_count += ft_putchar('%');
	return (p_count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		p_count;
	va_list	arg;

	p_count = 0;
	count = 0;
	va_start(arg, str);
	while (str[count])
	{
		if (str[count] == '%')
		{
			p_count += ft_format(str[++count], arg);
			count++;
		}
		else
			p_count += ft_putchar(str[count++]);
	}
	return (p_count);
}
