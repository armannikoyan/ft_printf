/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removeprefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:26:18 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/26 20:02:37 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_removeprefix(char *str, char c)
{
	char	*new_str;
	int		match_count;
	int		new_length;
	int		i;

	if (!str)
		return (NULL);
	match_count = 0;
	while (*str == c)
	{
		match_count++;
		str++;
	}
	new_length = 0;
	while (str[new_length])
		new_length++;
	new_str = malloc(new_length + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (str[++i + match_count])
		new_str[i] = str[i + match_count];
	new_str[i] = '\0';
	return (new_str);
}
