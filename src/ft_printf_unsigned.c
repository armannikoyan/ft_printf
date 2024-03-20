/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:00:15 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/20 19:09:01 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_process_flags(char **number, unsigned int *u_nbr,
	int *padding_width, t_flags *flags)
{
	int	result;
	int	len;

	result = 0;
	len = ft_strlen(*number);
	if (!(*u_nbr) && !flags->precision)
	{
		free(*number);
		*number = NULL;
		if (flags->width)
			(*padding_width)++;
	}
	if (flags->precision != -1 && flags->zero)
	{
		flags->width -= *padding_width;
		ft_printf_putchar(3, ' ', &result, padding_width);
	}
	flags->precision -= len;
	ft_printf_putchar(3, '0', &result, &flags->precision);
	if (flags->zero)
		ft_printf_putchar(3, '0', &result, padding_width);
	else if (!flags->minus)
		ft_printf_putchar(3, ' ', &result, padding_width);
	return (result);
}

int	ft_printf_unsigned(unsigned int u_nbr, t_flags flags)
{
	char	*number;
	int		result;
	int		len;
	int		padding_width;

	result = 0;
	number = ft_uitoa(u_nbr);
	if (!number)
		return (0);
	len = ft_strlen(number);
	padding_width = ft_calculate_padding(len, &flags);
	result += ft_process_flags(&number, &u_nbr, &padding_width, &flags);
	if (number)
	{
		result += ft_printf("%s", number);
		free(number);
		number = NULL;
	}
	if (flags.minus == 1)
		ft_printf_putchar(3, ' ', &result, &padding_width);
	return (result);
}
