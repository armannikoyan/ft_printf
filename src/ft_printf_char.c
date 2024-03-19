/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:51:55 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/11 22:46:32 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_handle_error(t_flags *flags)
{
	if (flags->zero || flags->hash || flags->space || flags->plus
		|| flags->precision != -1)
		return (1);
	return (0);
}

int	ft_printf_char(char c, t_flags flags)
{
	int	result;

	if (ft_handle_error(&flags))
		return (0);
	result = 0;
	flags.width--;
	if (!flags.minus)
		ft_printf_putchar(3, ' ', &result, &flags.width);
	ft_printf_putchar(2, c, &result);
	if (flags.minus)
		ft_printf_putchar(3, ' ', &result, &flags.width);
	return (result);
}
