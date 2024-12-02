# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 11:11:14 by jopereir          #+#    #+#              #
#    Updated: 2024/12/02 11:30:03 by jopereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftsolong.a

SRC = 
OBJ = $(SRC:.c=.o)
HEADER = include
LIBFT = libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(HEADER) -g
PROGRAM = so_long

all: $(NAME)

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

#Creates libft.a. Copy to the current directory. Add libft.a to libprintf.a
$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@echo "Creating $(NAME)."
	@ar rcs $(NAME) $(OBJ)

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

main: re
	@echo "Compiling main.c"
	@$(CC) $(CFLAGS) $(PROGRAM).c -L. -lftsolong -o $(PROGRAM)
	@$(MAKE) clean

.PHONY: all clean fclean re
