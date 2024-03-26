/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:27:06 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/25 18:46:43 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_padding(char c, int width)
{
	char	*padding;

	padding = NULL;
	padding = (char *)malloc(sizeof(char) * (width + 1));
	if (!padding)
		return (NULL);
	padding[width] = '\0';
	while (width--)
		padding[width] = c;
	return (padding);
}

static char	*ft_process_flags(char *hex, int *padding_width, t_flags *flags)
{
	char	*padding;
	char	*temp;

	padding = NULL;
	temp = NULL;
	if (flags->width > (int)ft_strlen(hex))
	{
		*padding_width = flags->width - ft_strlen(hex);
		padding = ft_padding(' ', *padding_width);
		if (!padding)
		{
			free(hex);
			return (NULL);
		}
		temp = hex;
		if (flags->minus == 0)
			hex = ft_strjoin(padding, hex);
		else if (flags->minus == 1)
			hex = ft_strjoin(hex, padding);
		free(temp);
		free(padding);
		if (!hex)
			return (NULL);
	}
	return (hex);
}

static char	*ft_convert_pointer(char *hex, size_t u_nbr)
{
	char	*ptr;

	hex = ft_uitoa_base(u_nbr, 16);
	if (!hex)
		return (NULL);
	ptr = hex;
	ptr = ft_strjoin("0x", hex);
	free(hex);
	if (!ptr)
		return (NULL);
	return (ptr);
}

int	ft_print_pointer(size_t u_nbr, t_flags *flags)
{
	char	*hex;
	int		result;
	int		len;
	int		padding_width;

	result = 0;
	hex = NULL;
	hex = ft_convert_pointer(hex, u_nbr);
	if (!hex)
		return (-1);
	padding_width = 0;
	hex = ft_process_flags(hex, &padding_width, flags);
	if (!hex)
		return (-1);
	len = ft_strlen(hex);
	if (hex)
	{
		result += len;
		if (ft_printf("%s", hex) == -1)
			result = -1;
		free(hex);
	}
	return (result);
}
