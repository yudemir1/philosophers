# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 18:32:53 by yudemir           #+#    #+#              #
#    Updated: 2025/04/25 03:06:03 by yudemir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = philo.c parse.c parse_utils.c test_helpers.c ft_split.c errors.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re