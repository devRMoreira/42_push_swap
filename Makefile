# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 14:57:15 by rimagalh          #+#    #+#              #
#    Updated: 2024/12/19 18:24:59 by rimagalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC = src/main.c \
	src/parse.c \
	src/parse_utils.c \
	src/sort.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = lib/libft
LIBFT = libft.a
LIBFT_REPO = https://github.com/devRMoreira/42_libft

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_DIR)/$(LIBFT)

$(LIBFT):
	if [ ! -d "$(LIBFT_DIR)" ]; then \
        git clone $(LIBFT_REPO) $(LIBFT_DIR); \
    else \
        cd $(LIBFT_DIR) && git pull origin main; \
    fi
	$(MAKE) -C $(LIBFT_DIR)

gdb: CFLAGS += -g
gdb: re

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
