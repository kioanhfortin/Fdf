# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:30:46 by kfortin           #+#    #+#              #
#    Updated: 2023/04/19 21:06:53 by kfortin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MLX = MLX42/build/libmlx42.a
GIT_MLX = https://github.com/codam-coding-college/MLX42.git

SRCS = 	ft_parsing.c get_next_line.c get_next_line_utils.c ft_list.c ft_split.c\
		fdf_utilis.c ft_image.c ft_modif_coor.c ft_modif_coor_iso_h.c ft_hook_handles.c\
		ft_hook_handles_2.c ft_atoi_base.c ft_read_map.c ft_init.c ft_error_ext.c\
		ft_hook_handles_3.c ft_hook_handles_4.c ft_hook_handles_5.c ft_modif_coor_iso_v.c\
		ft_modif_coor_hau_h.c ft_modif_coor_hau_v.c ft_read_map_h.c ft_read_map_v.c\
		ft_split_utilis.c\

	
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -r

all :	install $(NAME)

$(NAME) : $(MLX) $(OBJS)
	$(CC) $(OBJS) $(MLX) -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME) $(MLX)

install :

$(MLX) :
		brew update --quiet
		if brew list cmake &> /dev/null; then \
		echo "Process 1 : cmake"; \
	else \
		brew install cmake &> /dev/null; \
	fi 
		if brew list glfw &> /dev/null; then \
		echo "Process 2 : brew"; \
	else \
		brew install glfw &> /dev/null; \
	fi
		git clone $(GIT_MLX) &> /dev/null
		cd MLX42/ && cmake -B build &> /dev/null
		cd MLX42/ && cmake --build build -j4 &> /dev/null

$(OBJS): %.o: %.c
		$(CC) $(CFLAGS) -o3  -c $< -o $@
	
clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all