# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/05 09:51:22 by jopereir          #+#    #+#              #
#    Updated: 2024/11/12 10:54:40 by jopereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
#Directories
SRCS_DIR = src
HEADER_DIR = ../include

#Files
SRCS_FILES  = $(wildcard $(SRCS_DIR)/*.c)
OBJS_FILES = $(SRCS_FILES:.c=.o)

#compile -I. find for the header (.h) in current directory. -g to use valgrind
CC 		= gcc
CFLAGS 	= -Wall -Werror -Wextra -I$(HEADER_DIR) -g

#Rules
all: $(NAME)

#The flag -c is for compile to .o without linking. -o is for the file names
$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

#flag r is for replace, c if for create
$(NAME): $(OBJS_FILES)
	@echo "Creating lib $(NAME)"
	@ar rcs $(NAME) $(OBJS_FILES)

clean:
	@echo "Objects removed."
	@rm -f $(OBJS_FILES)

fclean: clean
	@echo "$(NAME) removed."
	@rm -f $(NAME) my_program


re:	fclean all

main: re
	@echo "Compiling main.c"
	@$(CC) $(CFLAGS) main.c -L. -lft -o my_program
	@$(MAKE) clean

.PHONY: all clean fclean re
