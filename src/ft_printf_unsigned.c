/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:00:15 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/21 09:29:46 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_unsigned(unsigned int u_nbr, t_flags *flags)
{
	char	*number;
	int		result;
	int		len;

	result = 0;
	number = ft_uitoa(u_nbr);
	if (!number)
		return (-1);
	len = ft_strlen(number);
	if (flags->minus == 1)
		flags->minus = 0; // remove
	if (number)
	{
		if (ft_printf("%s", number) == -1)
		{
			free(number);
			return (-1);
		}
		free(number);
		result += len;
	}
	return (result);
}
