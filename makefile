# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:30:46 by kfortin           #+#    #+#              #
#    Updated: 2023/04/18 17:31:20 by kfortin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MLX = ./MLX42/build/libmlx42.a

SRCS = 	ft_parsing.c get_next_line.c get_next_line_utils.c ft_list.c ft_split.c\
		fdf_utilis.c ft_image.c ft_modif_coor.c ft_modif_coor_iso_h.c ft_hook_handles.c\
		ft_hook_handles_2.c ft_atoi_base.c ft_read_map.c ft_init.c ft_error_ext.c\
		ft_hook_handles_3.c ft_hook_handles_4.c ft_hook_handles_5.c ft_modif_coor_iso_v.c\
		ft_modif_coor_hau_h.c ft_modif_coor_hau_v.c ft_read_map_h.c ft_read_map_v.c\
		ft_split_utilis.c\

%.o: %.c
	$(CC) -Wall -Wextra -Werror -o3  -c $< -o $@
	
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -r

all :	$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(MLX) -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all