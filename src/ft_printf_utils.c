/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:26:18 by anikoyan          #+#    #+#             */
/*   Updated: 2024/04/09 16:53:36 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_padding_width(char *number, t_flags *flags)
{
	int	padding_width;
	int	len;

	len = (int)ft_strlen(number);
	padding_width = flags->width - len;
	if (flags->minus != -1 && flags->precision >= len
		&& flags->precision < flags->width)
		padding_width = flags->width - flags->precision;
	else if (flags->precision > len)
		padding_width = flags->width - flags->precision;
	if ((flags->precision >= len && number[0] == '-') || (flags->plus == 1
			&& number[0] != '-'))
		padding_width--;
	if (flags->zero == 1 && padding_width > 0 && (len == 0
			|| flags->precision >= 0))
	{
		flags->minus = 0;
		flags->zero = 0;
	}
	if (flags->hash == 1 && number[0] != '0' && len > 0)
		padding_width -= 2;
	return (padding_width);
}
