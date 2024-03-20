/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:51:55 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/20 19:08:24 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_char(char c, t_flags flags)
{
	int	result;

	result = 0;
	flags.width--;
	if (!flags.minus)
		ft_printf_putchar(3, ' ', &result, &flags.width);
	ft_printf_putchar(2, c, &result);
	if (flags.minus == 1)
		ft_printf_putchar(3, ' ', &result, &flags.width);
	return (result);
}
