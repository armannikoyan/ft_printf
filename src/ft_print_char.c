/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:51:55 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/21 17:09:21 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_print_width(t_flags *flags, int *result)
{
	int	padding_width;

	padding_width = flags->width - 1;
	while (padding_width-- > 0 && flags->minus == 0)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		(*result)++;
	}
	return (1);
}

static int	ft_print_minus(t_flags *flags, int *result)
{
	int	padding_width;

	padding_width = flags->width - 1;
	while (padding_width-- > 0 && flags->minus == 1)
	{
		if (ft_putchar(' ') == -1)
			return (-1);
		(*result)++;
	}
	return (1);
}

int	ft_print_char(char c, t_flags *flags)
{
	int	result;
	int	tmp;

	result = 0;
	if (ft_print_width(flags, &result) == -1)
		return (-1);
	tmp = ft_putchar(c);
	if (tmp == -1)
		return (-1);
	result += tmp;
	if (ft_print_minus(flags, &result) == -1)
		return (-1);
	return (result);
}
