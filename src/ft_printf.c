/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:52:25 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/13 00:37:02 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_printf_helper(char c, va_list *args, t_flags flags)
{
	if (c == 'c')
		return (ft_printf_char(va_arg(*args, int), flags));
	if (c == '%')
		return (ft_printf_char('%', flags));
	if (c == 's')
		return (ft_printf_string(va_arg(*args, char *), flags));
	if (c == 'u')
		return (ft_printf_unsigned(va_arg(*args, unsigned int), flags));
	if (c == 'd' || c == 'i')
		return (ft_printf_int(va_arg(*args, int), flags));
	if (c == 'x' || c == 'X')
		return (ft_printf_hex(va_arg(*args, unsigned int), flags, c));
	if (c == 'p')
		return (ft_printf_pointer(va_arg(*args, size_t), flags));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	int		i;
	va_list	args;
	t_flags	flags;

	va_start(args, format);
	result = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			flags = ft_printf_parse_flags(&format[++i]);
			while (ft_strchr("0.-# +", format[i]) || ft_isdigit(format[i]))
				i++;
			result += ft_printf_helper(format[i], &args, flags);
		}
		else
			ft_printf_putchar(2, format[i], &result);
		i++;
	}
	va_end(args);
	return (result);
}
