/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:53:53 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 17:17:54 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_center(t_main *main)
{
	main->mat.center_x = (WINDOW_WIDTH / 2) - (main->mat.size_x / 2
			* main->mat.zoom);
	main->mat.center_y = (WINDOW_HEIGHT / 2) - (main->mat.size_y / 2
			* main->mat.zoom);
}

t_rat	*ft_color(t_rat *rat, t_mat *mat, int x, int y)
{
	if (rat->flag == 1)
	{
		if (mat->mat[y][x] > 0 && mat->mat[y][x - 1] > 0)
			rat->color = 1;
		else if (mat->mat[y][x] < 0 && mat->mat[y][x - 1] < 0)
			rat->color = -1;
		else if (mat->mat[y][x - 1] == 0 && mat->mat[y][x] == 0)
			rat->color = -2;
		else if ((mat->mat[y][x - 1] == 0 && mat->mat[y][x] < 0)
				|| (mat->mat[y][x - 1] < 0 && mat->mat[y][x] == 0))
			rat->color = 2;
	}
	else
	{
		if (mat->mat[y - 1][x] > 0 && mat->mat[y][x] > 0)
			rat->color = 1;
		else if (mat->mat[y - 1][x] < 0 && mat->mat[y][x] < 0)
			rat->color = -1;
		else if (mat->mat[y - 1][x] == 0 && mat->mat[y][x] == 0)
			rat->color = -2;
		else if ((mat->mat[y - 1][x] == 0 && mat->mat[y][x] < 0) || (mat->mat[y
					- 1][x] < 0 && mat->mat[y][x] == 0))
			rat->color = 2;
	}
	return (rat);
}

t_coor	*ft_init_coor(t_mat *mat)
{
	t_coor	*mat_coor;

	mat_coor = ft_calloc(sizeof(t_coor), mat->size_x * mat->size_y);
	mat_coor->temp_x = 0;
	mat_coor->temp_y = 0;
	mat_coor->rot_x = 0;
	mat_coor->rot_y = 0;
	return (mat_coor);
}

double	ft_deg_rad(int deg)
{
	double	rad;

	rad = deg * M_PI / 180.0;
	return (rad);
}
