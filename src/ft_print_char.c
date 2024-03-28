/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:51:55 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/28 06:16:45 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_print_width(t_flags *flags, int *result)
{
	int	padding_width;

	padding_width = flags->width - 1;
	if (flags->minus == 0 && padding_width > 0)
	{
		if (ft_putsymseq(' ', &padding_width, result) == -1)
			return (-1);
	}
	return (1);
}

static int	ft_print_minus(t_flags *flags, int *result)
{
	int	padding_width;

	padding_width = flags->width - 1;
	if (flags->minus == 1 && padding_width > 0)
	{
		if (ft_putsymseq(' ', &padding_width, result) == -1)
			return (-1);
	}
	return (1);
}

int	ft_print_char(char c, t_flags *flags)
{
	int	result;

	result = 0;
	if (ft_print_width(flags, &result) == -1)
		return (-1);
	if (ft_putchar(c, &result) == -1)
		return (-1);
	if (ft_print_minus(flags, &result) == -1)
		return (-1);
	return (result);
}
