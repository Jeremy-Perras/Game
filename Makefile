# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperras <jperras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 10:37:03 by jperras           #+#    #+#              #
#    Updated: 2022/04/06 18:47:15 by jeremyperras     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = game

SRCS = game.c ft_createmap.c get_next_line.c get_next_line_utils.c ft_image.c ft_image2.c \
		ft_windows.c ft_hooks.c ft_hooks3.c ft_utils.c ft_algo.c

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBMLX = -L minilibx -lmlx

LIBFT = -L libft -lft

LIBPF = -L printf -lftprintf

OTHER = -framework OpenGL -framework AppKit

.c.o:
		${CC} ${FLAGS} -I./includes  -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	make -C libft
	make -C printf
	make -C minilibx
	$(CC) $(FLAGS) -o $(NAME) $(LIBMLX) $(LIBPF) $(LIBFT) $(OTHER) $(INCLUDES) $(OBJS)

all : $(NAME)


test :
	$(CC) $(FLAGS) -o $(NAME) $(LIBMLX) $(LIBPF) $(LIBFT) $(INCLUDES) $(OTHER) $(SRCS)

debug :
	$(CC) -g $(FLAGS) -o $(NAME) $(LIBMLX) $(LIBPF) $(LIBFT) $(INCLUDES) $(OTHER) $(SRCS)

clean :
	make clean -C libft
	make clean -C printf
	make clean -C minilibx
	rm -rf $(OBJS)

fclean : clean
	make fclean -C libft
	make fclean -C printf
	make fclean -C minilibx
	rm -rf $(NAME)

re : fclean all
	make re -C libft
	make re -C printf
	make re -C minilibx
