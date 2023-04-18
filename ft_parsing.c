/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:47:54 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 17:42:54 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*ft_mapwid(char *argv, t_mat *mat, t_list *map)
{
	int		i;
	int		fd;
	t_list	*node;
	char	*str;

	i = 0;
	fd = open(argv, O_RDONLY);
	map = ft_lstnew(get_next_line(fd));
	node = map;
	str = map->str;
	if (map->str == NULL)
		ft_write_error();
	i++;
	mat->size_x = ft_maplen(map->str);
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (ft_maplen(str) > mat->size_x)
			ft_write_error();
		ft_lstadd_back(&node, ft_lstnew(str));
		node = (struct s_list *)node->next;
		i++;
	}
	mat->size_y = i - 1;
	return (map);
}

int	ft_maplen(char *str)
{
	int	i;
	int	len;
	int	flag;

	i = 0;
	len = 0;
	flag = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1 && (ft_isspace(str[i - 1]) == 1 || str[i
					- 1] == '-' || str[i - 1] == '+' || flag == 0))
		{
			len++;
			flag = 1;
		}
		i++;
	}
	return (len);
}

void	ft_stock_mat(t_mat *mat, t_list *map)
{
	int		x;
	int		y;
	int		flag;
	t_list	*node;

	x = 0;
	y = 0;
	flag = 1;
	node = map;
	mat->mat = ft_calloc(mat->size_y + 1, sizeof(int *));
	if (!mat->mat)
		return ;
	while (y < mat->size_y)
	{
		if (node->str)
		{
			mat->mat[y] = ft_split(node->str, "\t\n\r\v\f ");
			node = (struct s_list *)node->next;
		}
		y++;
	}
}

t_mat	ft_parsing(char **argv)
{
	t_list	*map;
	t_mat	mat;

	map = NULL;
	ft_init_struct(&mat);
	ft_tchek_ext(argv[1]);
	map = ft_mapwid(argv[1], &mat, map);
	ft_stock_mat(&mat, map);
	if (ft_tchek_rect(&mat, map) == 0)
		ft_write_error();
	ft_listclear(map);
	return (mat);
}

int	main(int argc, char **argv)
{
	t_main	main;

	if (argc == 2)
	{
		main.mat = ft_parsing(argv);
		main.mat_coor = ft_init_coor(&main.mat);
		main.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "KIOWINDOW", false);
		main.img = mlx_new_image(main.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		ft_fill_coor_hori(&main);
		ft_fill_coor_vert(&main);
		mlx_image_to_window(main.mlx, main.img, 0, 0);
		mlx_key_hook(main.mlx, &handle_keyboard, &main);
		mlx_mouse_hook(main.mlx, &handle_mouse, &main);
		mlx_loop(main.mlx);
		mlx_close_hook(main.mlx, ft_exit(&main), &main);
		if (main.mat.mat)
			ft_free_tab2((void **)main.mat.mat);
	}
	else
		ft_write_error();
	return (0);
}
