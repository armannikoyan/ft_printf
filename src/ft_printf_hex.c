/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:55:00 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/21 09:37:54 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_str_toupper(char *str, char c)
{
	if (c == 'X')
	{
		while (*str)
		{
			*str = ft_toupper(*str);
			str++;
		}
	}
}

int	ft_print_hex(unsigned int u_nbr, t_flags *flags, char c)
{
	char	*hex;
	int		result;
	int		len;

	result = 0;
	hex = ft_uitoa_base(u_nbr, 16);
	if (!hex)
		return (-1);
	len = ft_strlen(hex);
	if (flags->minus == 1)
		flags->minus = 0;
	if (hex)
	{
		ft_str_toupper(hex, c);
		if (ft_printf("%s", hex) == -1)
		{
			free(hex);
			return (-1);
		}
		free(hex);
		result += len;
	}
	return (result);
}
