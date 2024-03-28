/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsymseq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 04:31:41 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/28 06:24:14 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putsymseq(char c, int *count, int *result)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (*count + 1));
	if (!str)
		return (-1);
	i = 0;
	while (i < *count)
		str[i++] = c;
	str[i] = '\0';
	if (write(1, str, *count) == -1)
		*count = -1;
	free(str);
	*result += *count;
	return (*count);
}
