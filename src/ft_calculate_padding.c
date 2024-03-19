/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_padding.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:31:22 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/12 16:35:33 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_calculate_padding(int len, t_flags *flags)
{
	int	padding_width;

	if (flags->precision > len)
		padding_width = flags->width - flags->precision;
	else
		padding_width = flags->width - len;
	return (padding_width);
}
