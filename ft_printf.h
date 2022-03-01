/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyildiz <seyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:46:07 by seyildiz          #+#    #+#             */
/*   Updated: 2022/02/19 18:52:52 by seyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_putbase(long double n, char c, int b);
int	ft_putnbr(int nbr);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_format(char c, va_list arg);

#endif