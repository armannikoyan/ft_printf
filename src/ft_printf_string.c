/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:08:48 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/20 19:08:35 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_string(char *str, t_flags flags)
{
	int	result;
	int	len;
	int	padding_width;

	if (!str)
		str = "(null)";
	result = 0;
	len = ft_strlen(str);
	if (flags.precision != -1 && flags.precision < len)
		len = flags.precision;
	padding_width = flags.width - len;
	if (!flags.minus)
		ft_printf_putchar(3, ' ', &result, &padding_width);
	while (*str && len--)
		ft_printf_putchar(2, *str++, &result);
	if (flags.minus == 1)
		ft_printf_putchar(3, ' ', &result, &padding_width);
	return (result);
}
