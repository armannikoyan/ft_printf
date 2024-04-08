/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:55:00 by anikoyan          #+#    #+#             */
/*   Updated: 2024/04/08 16:35:40 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_str_toupper(char *str, int upper)
{
	if (upper)
	{
		while (*str)
		{
			*str = ft_toupper(*str);
			str++;
		}
	}
}

int	ft_print_hex(unsigned int u_nbr, t_flags *flags)
{
	char	*hex;
	int		result;
	int		len;
	int		padding_width;

	result = 0;
	hex = ft_uitoa_base(u_nbr, 16);
	if (!hex)
		return (-1);
	padding_width = ft_padding_width(hex, flags);
	hex = ft_process_flags(hex, &padding_width, &result, flags);
	if (!hex)
		return (-1);
	ft_str_toupper(hex, flags->upper);
	len = ft_strlen(hex);
	result += len;
	if (ft_printf("%s", hex) == -1)
	{
		free(hex);
		return (-1);
	}
	free(hex);
	if (flags->minus == 1 && padding_width > 0)
	{
		if (ft_putsymseq(' ', &padding_width, &result) == -1)
			return (-1);
	}
	return (result);
}
