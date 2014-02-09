#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/18 17:26:04 by amorfan           #+#    #+#              #
#    Updated: 2014/01/18 19:34:34 by amorfan          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

FLAGS = -L/usr/X11/lib -lmlx -lXext -lX11

SRCS =	main.c			\
		getnbr.c		\
		ft_draw.c		\
		ft_raycasting.c	\
		ft_key_init.c	\
		ft_move.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	gcc $(CFLAGS) -o $(NAME) $(FLAGS) $(SRCS) libft/libft.a

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
