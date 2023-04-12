# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:30:46 by kfortin           #+#    #+#              #
#    Updated: 2023/04/10 17:35:47 by kfortin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = 	ft_parsing.c get_next_line.c get_next_line_utils.c ft_list.c ft_split.c\
		fdf_utilis.c ft_algo_line.c ft_image.c ft_modif_coor.c ft_command_to_screen.c\

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g  -c $< -o $@
	
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -r

all :	$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all