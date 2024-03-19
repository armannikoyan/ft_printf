/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:44:29 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/12 16:31:39 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_handle_error(t_flags *flags)
{
	if (flags->hash)
		return (1);
	return (0);
}

static void	ft_remove_sign_from_string(char **number, int *len, int *result)
{
	char	*new_number;

	new_number = ft_strdup(&number[0][1]);
	free(*number);
	*number = new_number;
	*len = ft_strlen(*number);
	ft_printf_putchar(2, '-', result);
}

static int	ft_process_flags_helper(char **number, int *nbr,
	int *padding_width, t_flags *flags)
{
	int	result;
	int	len;

	result = 0;
	len = ft_strlen(*number);
	if (!(*nbr) && !flags->precision)
	{
		free(*number);
		*number = NULL;
		if (flags->width)
			(*padding_width)++;
	}
	if (flags->precision != -1 && flags->zero)
	{
		if (*number && **number == '-' && flags->precision > len)
			(*padding_width)--;
		ft_printf_putchar(3, ' ', &result, padding_width);
	}
	if (flags->space && *nbr >= 0)
		ft_printf_putchar(2, ' ', &result);
	else if (flags->plus && *nbr >= 0)
		ft_printf_putchar(2, '+', &result);
	return (result);
}

static int	ft_process_flags(char **number, int *nbr,
	int *padding_width, t_flags *flags)
{
	int	result;
	int	len;

	len = ft_strlen(*number);
	result = ft_process_flags_helper(number, nbr, padding_width, flags);
	if (flags->precision != -1)
	{
		if (*number && **number == '-')
		{
			ft_remove_sign_from_string(number, &len, &result);
			if (flags->precision > len)
				(*padding_width)--;
		}
		flags->precision -= len;
		ft_printf_putchar(3, '0', &result, &flags->precision);
	}
	if (flags->zero)
	{
		if (*number && **number == '-')
			ft_remove_sign_from_string(number, &len, &result);
		ft_printf_putchar(3, '0', &result, padding_width);
	}
	else if (!flags->minus)
		ft_printf_putchar(3, ' ', &result, padding_width);
	return (result);
}

int	ft_printf_int(int nbr, t_flags flags)
{
	char	*number;
	int		result;
	int		len;
	int		padding_width;

	if (ft_handle_error(&flags))
		return (0);
	result = 0;
	number = ft_itoa(nbr);
	if (!number)
		return (0);
	len = ft_strlen(number);
	padding_width = ft_calculate_padding(len, &flags);
	result += ft_process_flags(&number, &nbr, &padding_width, &flags);
	if (number)
	{
		result += ft_printf("%s", number);
		free(number);
		number = 0;
	}
	if (flags.minus)
		ft_printf_putchar(3, ' ', &result, &padding_width);
	return (result);
}
