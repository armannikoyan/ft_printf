# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 23:53:16 by anikoyan          #+#    #+#              #
#    Updated: 2024/03/10 20:24:14 by anikoyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
       ft_isascii.c ft_isprint.c ft_strlen.c \
       ft_memset.c ft_bzero.c ft_memcpy.c \
       ft_memmove.c ft_strlcpy.c ft_strlcat.c \
       ft_toupper.c ft_tolower.c ft_strchr.c \
       ft_strrchr.c ft_strncmp.c ft_memchr.c \
       ft_memcmp.c ft_strnstr.c ft_atoi.c \
       ft_calloc.c ft_strdup.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c \
       ft_itoa.c ft_strmapi.c ft_striteri.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
       ft_putnbr_fd.c
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.c=.o)))

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	     ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	     ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_BONUS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS_BONUS:.c=.o)))

CC = cc
C_FLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
RM = rm -f

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS_BONUS)
	ar $(ARFLAGS) $(NAME) $(OBJS_BONUS)

$(OBJS_BONUS): $(OBJ_DIR)/%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	rm -r $(OBJ_DIR) 2>/dev/null || true

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
