/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:02:18 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/11 16:36:54 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	*ft_get_length(int arg_count, va_list args)
{
	int	*length;

	length = NULL;
	if (arg_count == 3)
		length = va_arg(args, int *);
	else if (arg_count == 2)
	{
		length = malloc(sizeof(int));
		if (!length)
			return (NULL);
		*length = 1;
	}
	return (length);
}

void	ft_printf_putchar(int arg_count, ...)
{
	va_list	args;
	char	c;
	int		*length;
	int		*result;

	if (arg_count < 2 || arg_count > 3)
		return ;
	va_start(args, arg_count);
	c = va_arg(args, int);
	result = va_arg(args, int *);
	length = ft_get_length(arg_count, args);
	if (!length)
		return ;
	while ((*length)-- > 0)
	{
		ft_putchar_fd(c, 1);
		(*result)++;
	}
	if (arg_count == 2)
		free(length);
	va_end(args);
}
