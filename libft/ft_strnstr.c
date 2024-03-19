/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:50:11 by anikoyan          #+#    #+#             */
/*   Updated: 2024/02/01 23:50:12 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	char	*null_pointer;

	null_pointer = NULL;
	needle_len = ft_strlen(needle);
	if (!haystack && len)
		*null_pointer = 'a';
	if (!needle_len)
		return ((char *)haystack);
	while (len >= needle_len && *haystack)
	{
		if (!ft_strncmp(haystack, needle, needle_len))
		{
			return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
