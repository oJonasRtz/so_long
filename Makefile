# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 11:11:14 by jopereir          #+#    #+#              #
#    Updated: 2024/12/09 13:20:34 by jopereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftsolong.a

SRC_DIR = src
SRCS = game_run.c read_map.c
SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(SRC:.c=.o)
HEADER = include
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(HEADER) -g
PROGRAM = so_long

all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

#Creates libft.a. Copy to the current directory. Add libft.a to libprintf.a
$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	
	@echo "Creating $(NAME)."
	@ar rcs $(NAME) $(OBJ)
	
	@echo "Compiling main.c"
	@$(CC) $(CFLAGS) $(SRC_DIR)/main.c -L. -lftsolong -lmlx -lX11 -lXext -lm -o $(PROGRAM)
	@$(MAKE) clean

clean:
	@echo "Objects removed."
	@rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	@echo "$(NAME) removed."
	@rm -f $(NAME)
	@rm -f $(PROGRAM)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
