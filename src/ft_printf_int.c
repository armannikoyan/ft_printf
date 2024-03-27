/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:44:29 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/27 23:01:27 by anikoyan         ###   ########.fr       */
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
	char	*new_number;
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
	if (*number == '-')
		flags->precision++;
	if (flags->precision > len && len > 0)
	{
		new_number = (char *)malloc(sizeof(char) * (flags->precision + 1));
		if (!new_number)
		{
			free(number);
			return (NULL);
		}
		i = 0;
		ptr = number;
		if (*number == '-')
		{
			new_number[i++] = *number++;
			flags->precision++;
		}
		while (i < flags->precision - len)
			new_number[i++] = '0';
		while (*number)
			new_number[i++] = *number++;
		new_number[i] = '\0';
		free(ptr);
		number = new_number;
	}
	len = (int)ft_strlen(number);
	i = 0;
	if (flags->plus == 1 && number[0] != '-')
	{
		new_number = (char *)malloc(sizeof(char) * (len + 2));
		if (!new_number)
		{
			free(number);
			return (NULL);
		}
		ptr = number;
		new_number[i++] = '+';
		while (*number && i < len + 1)
			new_number[i++] = *number++;
		new_number[i] = '\0';
		free(ptr);
		number = new_number;
	}
	len = (int)ft_strlen(number);
	i = 0;
	padding_width = ft_padding_width(number, flags);
	if (flags->minus != -1 && padding_width > 0)
	{
		new_number = (char *)malloc(sizeof(char) * (len + padding_width + 1));
		if (!new_number)
		{
			free(number);
			return (NULL);
		}
		if (flags->minus == 0)
		{
			ptr = number;
			while (i < padding_width)
				new_number[i++] = ' ';
			while (*number && i < len + padding_width)
				new_number[i++] = *number++;
			new_number[i] = '\0';
			free(ptr);
		}
		else
		{
			ptr = number;
			while (*number)
				new_number[i++] = *number++;
			while (i < len + padding_width)
				new_number[i++] = ' ';
			new_number[i] = '\0';
			free(ptr);
		}
		number = new_number;
	}
	return (number);
}

int	ft_print_int(int nbr, t_flags *flags)
{
	char	*number;
	int		result;
	int		len;
	int		padding_width;

	number = ft_itoa(nbr);
	if (!number)
		return (-1);
	result = 0;
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
