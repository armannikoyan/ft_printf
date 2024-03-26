/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:08:48 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/21 18:06:27 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_print_width(int padding_width, t_flags *flags, int *result)
{
	while (padding_width-- > 0 && flags->minus == 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		(*result)++;
	}
	return (1);
}

static int	ft_print_minus(int padding_width, t_flags *flags, int *result)
{
	while (padding_width-- > 0 && flags->minus == 1)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		(*result)++;
	}
	return (1);
}

int	ft_print_string(char *str, t_flags *flags)
{
	int	result;
	int	len;
	int	padding_width;

	if (!str)
		str = "(null)";
	result = 0;
	len = ft_strlen(str);
	if (flags->precision >= 0 && flags->precision < len)
		len = flags->precision;
	padding_width = flags->width - len;
	if (ft_print_width(padding_width, flags, &result) == -1)
		return (-1);
	while (*str && len-- > 0)
	{
		if (ft_putchar(*str) == -1)
			return (-1);
		str++;
		result++;
	}
	if (ft_print_minus(padding_width, flags, &result) == -1)
		return (-1);
	return (result);
}
