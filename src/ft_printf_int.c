/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:44:29 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/26 21:48:51 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_padding_width(char *number, t_flags *flags)
{
	int	padding_width;
	int	len;

	padding_width = 0;
	len = (int)ft_strlen(number);
	padding_width = flags->width - len;
	if (padding_width < 0)
		padding_width = 0;
	return (padding_width);
}

char	*ft_process_flags(char *number, int padding_width, t_flags *flags)
{
	char	*padding;
	char	*ptr;
	int		i;
	int		len;

	if (flags->precision == 0 && number[0] == '0')
	{
		free(number);
		number = ft_strdup("");
		if (!number)
			return (NULL);
	}
	len = (int)ft_strlen(number);
	if (ft_strchr(number, '-'))
		len--;
	if (flags->precision > len && len > 0)
	{
		padding = (char *)malloc(sizeof(char) * (flags->precision - len + 1));
		if (!padding)
		{
			free(number);
			return (NULL);
		}
		i = 0;
		while (i < flags->precision - len)
			padding[i++] = '0';
		padding[i] = '\0';
		if (number[0] == '-')
		{
			ptr = ft_strdup(number + 1);
			free(number);
			if (!ptr)
			{
				free(padding);
				return (NULL);
			}
			number = ptr;
			ptr = padding;
			padding = ft_strjoin("-", ptr);
			free(ptr);
			if (!padding)
			{
				free(number);
				return (NULL);
			}
			ptr = number;
			number = ft_strjoin(padding, ptr);
			free(ptr);
			if (!number)
			{
				free(padding);
				return (NULL);
			}
		}
		else
		{
			ptr = number;
			number = ft_strjoin(padding, ptr);
			free(ptr);
		}
		free(padding);
		if (!number)
			return (NULL);
	}
	padding_width = ft_padding_width(number, flags);
	i = 0;
	if (flags->plus == 1 && !ft_strchr(number, '-'))
	{
		ptr = number;
		number = ft_strjoin("+", ptr);
		free(ptr);
		if (!number)
			return (NULL);
	}
	padding_width = ft_padding_width(number, flags);
	if (flags->minus != -1 && padding_width > 0)
	{
		padding = (char *)malloc(sizeof(char) * (padding_width + 1));
		if (!padding)
		{
			free(number);
			return (NULL);
		}
		while (i < padding_width)
			padding[i++] = ' ';
		padding[i] = '\0';
		ptr = number;
		if (flags->minus == 0)
			number = ft_strjoin(padding, ptr);
		else if (flags->minus == 1)
			number = ft_strjoin(ptr, padding);
		free(ptr);
		free(padding);
		if (!number)
			return (NULL);
	}
	return (number);
}

int	ft_print_int(int nbr, t_flags *flags)
{
	char	*number;
	int		result;
	int		len;
	int		padding_width;

	result = 0;
	number = ft_itoa(nbr);
	if (!number)
		return (-1);
	padding_width = ft_padding_width(number, flags);
	number = ft_process_flags(number, padding_width, flags);
	if (!number)
		return (-1);
	len = (int)ft_strlen(number);
	if (number)
	{
		result += len;
		if (ft_printf("%s", number) == -1)
			result = -1;
		free(number);
	}
	return (result);
}
