# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 18:24:23 by anikoyan          #+#    #+#              #
#    Updated: 2024/03/28 04:45:40 by anikoyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_DIR = src
SRCS = $(SRCS_DIR)/ft_printf.c $(SRCS_DIR)/ft_putchar.c $(SRCS_DIR)/ft_strrev.c \
       $(SRCS_DIR)/ft_uitoa.c $(SRCS_DIR)/ft_uitoa_base.c $(SRCS_DIR)/ft_removeprefix.c \
       $(SRCS_DIR)/ft_strcpy.c $(SRCS_DIR)/ft_strcat.c $(SRCS_DIR)/ft_print_char.c \
       $(SRCS_DIR)/ft_print_string.c $(SRCS_DIR)/ft_printf_parse_flags.c $(SRCS_DIR)/ft_printf_unsigned.c \
       $(SRCS_DIR)/ft_printf_int.c $(SRCS_DIR)/ft_printf_hex.c $(SRCS_DIR)/ft_printf_pointer.c \
       $(SRCS_DIR)/ft_putsymseq.c $(SRCS_DIR)/ft_putstr.c
OBJS_DIR = obj
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC = -I $(LIBFT_DIR)

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: all

clean:
	$(RM) -r $(OBJS_DIR) 2>/dev/null || true
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
