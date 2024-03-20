/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:27:06 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/20 19:08:13 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_add_sign_to_string(char **number, int *len)
{
	char	*new_number;
	int		new_len;

	new_len = *len + 2;
	new_number = malloc(sizeof(char) * (new_len + 1));
	ft_strlcpy(new_number, "0x", (sizeof(char) * (new_len + 1)));
	ft_strlcat(new_number, *number, (sizeof(char) * (new_len + 1)));
	free(*number);
	*number = new_number;
	*len = new_len;
}

static int	ft_process_flags(char **hex, size_t *u_nbr,
	int *padding_width, t_flags *flags)
{
	int	result;
	int	len;

	result = 0;
	len = ft_strlen(*hex);
	if (!(*u_nbr) && !flags->precision)
	{
		if (flags->width)
			(*padding_width)++;
		free(*hex);
		*hex = NULL;
	}
	if (flags->precision != -1 && flags->zero)
		ft_printf_putchar(3, ' ', &result, padding_width);
	flags->precision -= len;
	ft_printf_putchar(3, '0', &result, &flags->precision);
	if (flags->zero)
		ft_printf_putchar(3, '0', &result, padding_width);
	else if (flags->plus)
		ft_printf_putchar(2, '+', &result);
	else if (!flags->minus)
		ft_printf_putchar(3, ' ', &result, padding_width);
	return (result);
}

int	ft_printf_pointer(size_t u_nbr, t_flags flags)
{
	char	*hex;
	int		result;
	int		len;
	int		padding_width;

	result = 0;
	hex = ft_uitoa_base(u_nbr, 16);
	if (!hex)
		return (0);
	ft_strrev(hex);
	len = ft_strlen(hex);
	ft_add_sign_to_string(&hex, &len);
	padding_width = ft_calculate_padding(len, &flags);
	result += ft_process_flags(&hex, &u_nbr, &padding_width, &flags);
	if (hex)
	{
		ft_printf("%s", hex);
		result += len;
		free(hex);
	}
	if (flags.minus == 1)
		ft_printf_putchar(3, ' ', &result, &padding_width);
	return (result);
}
