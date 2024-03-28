/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:44:29 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/28 07:00:11 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_padding_width(char *number, t_flags *flags)
{
	int	padding_width;
	int	len;

	len = (int)ft_strlen(number);
	if (flags->precision - len > 0)
		padding_width = flags->width - flags->precision;
	else
		padding_width = flags->width - len;
	if (padding_width < 0)
		padding_width = 0;
	else if (flags->plus == 1 && number[0] != '-')
		padding_width--;
	if (padding_width == 0 && flags->space == 1 && number[0] != '-')
		padding_width++;
	return (padding_width);
}

static char	*ft_process_flags(char *number, int *padding_width, int *result, t_flags *flags)
{
	char	*ptr;
	int		len;

	if (flags->precision == 0 && number[0] == '0')
	{
		free(number);
		number = ft_strdup("");
		if (!number)
			return (NULL);
	}
	*padding_width = ft_padding_width(number, flags);
	if ((flags->minus == 0 || flags->space == 1) && *padding_width > 0)
	{
		if (ft_putsymseq(' ', padding_width, result) == -1)
		{
			free(number);
			return (NULL);
		}
	}
	if (flags->plus == 1 && number[0] != '-')
	{
		if (ft_putchar('+', result) == -1)
		{
			free(number);
			return (NULL);
		}
		(*padding_width)--;
	}
	if (flags->precision > 0 && flags->zero == 1 && *padding_width > 0)
	{
		flags->precision -= *padding_width;
		if (ft_putsymseq(' ', padding_width, result) == -1)
		{
			free(number);
			return (NULL);
		}
	}
	len = (int)ft_strlen(number);
	if (number[0] == '-')
	{
		if (ft_putchar('-', result) == -1)
		{
			free(number);
			return (NULL);
		}
		ptr = ft_strdup(number + 1);
		free(number);
		if (!ptr)
			return (NULL);
		number = ptr;
		flags->precision++;
	}
	if (flags->zero == 1 && flags->precision <= 0 && *padding_width > 0)
	{
		if (ft_putsymseq('0', padding_width, result) == -1)
		{
			free(number);
			return (NULL);
		}
	}
	if (flags->precision - len > 0)
	{
		flags->precision -= len;
		if (ft_putsymseq('0', &flags->precision, result) == -1)
		{
			free(number);
			return (NULL);
		}
	}
	return (number);
}

int	ft_print_int(int nbr, t_flags *flags)
{
	char	*number;
	int		result;
	int		padding_width;

	number = ft_itoa(nbr);
	if (!number)
		return (-1);
	result = 0;
	padding_width = ft_padding_width(number, flags);
	number = ft_process_flags(number, &padding_width, &result, flags);
	if (!number)
		return (-1);
	result += ft_putstr(number);
	free(number);
	if (flags->minus == 1 && padding_width > 0)
	{
		if (ft_putsymseq(' ', &padding_width, &result) == -1)
			return (-1);
	}
	return (result);
}

