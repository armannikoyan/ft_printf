/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:05:06 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/11 19:07:07 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_digit_count(unsigned int u_nbr)
{
	int	count;

	count = 0;
	if (!u_nbr)
		count++;
	while (u_nbr)
	{
		count++;
		u_nbr /= 10;
	}
	return (count);
}

char	*ft_uitoa(unsigned int u_nbr)
{
	char	*number;
	int		str_len;

	str_len = ft_digit_count(u_nbr);
	number = malloc(sizeof(char) * (str_len + 1));
	if (!number)
		return (NULL);
	number[str_len] = '\0';
	if (u_nbr == 0)
		number[0] = '0';
	while (u_nbr)
	{
		number[--str_len] = u_nbr % 10 + '0';
		u_nbr /= 10;
	}
	return (number);
}
