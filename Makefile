# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinursul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 10:43:14 by dinursul          #+#    #+#              #
#    Updated: 2024/12/16 11:30:36 by dinursul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f
SRC		= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Archiving objects into $(NAME)..."
	$(AR) $(NAME) $(OBJ)
	@echo "$(NAME) created."

%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files..."
	$(RM) $(OBJ)

fclean:
	@echo "Removing $(NAME)..."
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
