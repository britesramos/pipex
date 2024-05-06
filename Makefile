# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sramos <sramos@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2024/04/29 17:08:34 by sramos        #+#    #+#                  #
#    Updated: 2024/04/29 17:10:42 by sramos        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC = 
# Add all the src.c files here.

OBJ = $(SRC:%.c=%.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -Ilibft -g3
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) -Llibft -lft -o $(NAME)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean:
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY = all, clean, fclean, re
