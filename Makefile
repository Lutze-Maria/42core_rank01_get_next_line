# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lschawer <lschawer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 15:21:59 by lschawer          #+#    #+#              #
#    Updated: 2026/04/27 15:49:17 by lschawer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 1. Variables
NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
AR          = ar rcs
RM          = rm -f

# 2. Source Files
SRCS        = get_next_line.c get_next_line_utils.c 

# 3. Object Files
# This pattern substitution replaces the .c extension with .o
OBJS        = $(SRCS:.c=.o)

# 4. Mandatory Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# This rule explains how to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# 5. Phony Targets
# This prevents make from confusing these rules with files of the same name
.PHONY: all clean fclean re
