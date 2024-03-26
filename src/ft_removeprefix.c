/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removeprefic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:26:18 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/26 17:33:53 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_match(char *str, char c)
{
	int	count;

	count = 0;
	while (*str == c)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_removeprefix(char *str, char c)
{
	char	*new_str;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(str) - ft_match(str, c) + 1));
	i = 0;
	j = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
		new_str[j++] = str[i++];
	return (new_str);
}
