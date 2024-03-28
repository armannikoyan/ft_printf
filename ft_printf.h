/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:44:12 by anikoyan          #+#    #+#             */
/*   Updated: 2024/03/28 06:16:31 by anikoyan         ###   ########.fr       */
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

char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
char	*ft_uitoa(unsigned int u_nbr);
char	*ft_uitoa_base(size_t u_nbr, int base);
char	*ft_removeprefix(char *str, char c);

int		ft_putchar(char c, int *result);
int		ft_putstr(char *str);
int		ft_putsymseq(char c, int *count, int *result);
int		ft_printf(const char *fmt, ...);
int		ft_print_char(char c, t_flags *flags);
int		ft_print_string(char *str, t_flags *flags);
int		ft_print_unsigned(unsigned int u_nbr, t_flags *flags);
int		ft_print_int(int nbr, t_flags *flags);
int		ft_print_hex(unsigned int u_nbr, t_flags *flags, char c);
int		ft_print_pointer(size_t u_nbr, t_flags *flags);

t_flags	ft_printf_parse_flags(const char *fmt);

#endif
