/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:01:48 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/20 20:43:04 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_init_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = -1;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->precision = -1;
}

static void	ft_parse_width(const char *format, t_flags *flags)
{
	if (!flags->zero && flags->minus == -1 && !flags->hash
		&& flags->precision == -1)
		flags->minus = 0;
	if (ft_isdigit(*format))
		flags->width = ft_atoi(format);
}

static void	ft_parse_precision(const char *format, t_flags *flags)
{
	if (*format == '.')
	{
		format++;
		if (ft_isdigit(*format))
			flags->precision = ft_atoi(format);
		else
			flags->precision = 0;
	}
}

t_flags	ft_printf_parse_flags(const char *format)
{
	t_flags	flags;

	ft_init_flags(&flags);
	while (*format && ft_strchr("0-# +", *format))
	{
		if (*format == '0')
			flags.zero = 1;
		else if (*format == '-')
			flags.minus = 1;
		else if (*format == '#')
			flags.hash = 1;
		else if (*format == ' ')
			flags.space = 1;
		else if (*format == '+')
			flags.plus = 1;
		format++;
	}
	ft_parse_width(format, &flags);
	while (ft_isdigit(*format))
		format++;
	ft_parse_precision(format, &flags);
	return (flags);
}
