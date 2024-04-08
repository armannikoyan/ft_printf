/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:03:51 by anikoyan          #+#    #+#             */
/*   Updated: 2024/04/08 16:26:36 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_process_minus_space(char *number, int *padding_width
	, int *result, t_flags *flags)
{
	if (flags->minus == 0 && *padding_width > 0)
	{
		if (ft_putsymseq(' ', padding_width, result) == -1)
		{
			free(number);
			return (NULL);
		}
	}
	if (flags->hash == 1 && number[0] != '0' && (int)ft_strlen(number) > 0)
	{
		if (flags->upper)
		{
			if (write(1, "0X", 2) == -1)
			{
				free(number);
				return (NULL);
			}
		}
		else
		{
			if (write(1, "0x", 2) == -1)
			{
				free(number);
				return (NULL);
			}
		}
		*result += 2;
	}
	if (flags->space == 1 && number[0] != '-' && flags->plus == 0
		&& (flags->minus == -1 || (flags->minus == 0
				&& *padding_width <= 0) || flags->minus == 1))
	{
		if (ft_putchar(' ', result) == -1)
		{
			free(number);
			return (NULL);
		}
		(*padding_width)--;
	}
	return (number);
}

static char	*ft_process_zero_precision(char *number, int *padding_width
	, int *result, t_flags *flags)
{
	int	len;

	len = (int)ft_strlen(number);
	number = ft_removeminus(number, result, &len);
	if (flags->zero == 1 && *padding_width > 0)
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

char	*ft_process_flags(char *number, int *padding_width
		, int *result, t_flags *flags)
{
	if (flags->precision == 0 && number[0] == '0')
	{
		free(number);
		number = ft_strdup("");
		if (!number)
			return (NULL);
	}
	*padding_width = ft_padding_width(number, flags);
	number = ft_process_minus_space(number, padding_width, result, flags);
	if (!number)
		return (NULL);
	if (flags->plus == 1 && number[0] != '-')
	{
		if (ft_putchar('+', result) == -1)
		{
			free(number);
			return (NULL);
		}
	}
	number = ft_process_zero_precision(number, padding_width, result, flags);
	return (number);
}
