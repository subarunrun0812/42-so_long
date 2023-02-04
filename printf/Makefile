# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:15:24 by susasaki          #+#    #+#              #
#    Updated: 2023/01/10 00:44:44 by subarunrun       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES_DIR = ./srcs

LIBFT_DIR		=	./libft
LIBFT			=	$(LIBFT_DIR)/libft.a

SOURCES = $(SOURCES_DIR)/ft_change_base.c \
          $(SOURCES_DIR)/ft_printf.c \
          $(SOURCES_DIR)/ft_put_char.c \
          $(SOURCES_DIR)/ft_put_hexlower.c \
          $(SOURCES_DIR)/ft_put_hexupper.c \
          $(SOURCES_DIR)/ft_put_int.c \
          $(SOURCES_DIR)/ft_put_point.c \
          $(SOURCES_DIR)/ft_put_string.c \
          $(SOURCES_DIR)/ft_put_uint.c \
          $(SOURCES_DIR)/ft_tolower_all.c \
          $(SOURCES_DIR)/ft_toupper_all.c \

OBJS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror  -I libft -I header

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean : 
	make clean -C $(LIBFT_DIR) 
	rm -f $(OBJS)

fclean :
	make fclean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(NAME)

re : fclean all