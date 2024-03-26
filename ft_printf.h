/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:44:12 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/26 17:32:05 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_flags
{
	int	zero;
	int	minus;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	precision;
}		t_flags;

void	ft_strrev(char *str);

char	*ft_uitoa(unsigned int u_nbr);
char	*ft_uitoa_base(size_t u_nbr, int base);
char	*ft_removeprefix(char *str, char c);

int		ft_putchar(char c);
int		ft_printf(const char *fmt, ...);
int		ft_print_char(char c, t_flags *flags);
int		ft_print_string(char *str, t_flags *flags);
int		ft_print_unsigned(unsigned int u_nbr, t_flags *flags);
int		ft_print_int(int nbr, t_flags *flags);
int		ft_print_hex(unsigned int u_nbr, t_flags *flags, char c);
int		ft_print_pointer(size_t u_nbr, t_flags *flags);

t_flags	ft_printf_parse_flags(const char *fmt);

#endif
