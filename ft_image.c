/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:32:55 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 13:48:56 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_check_frame(t_rat *rat, t_main main)
{
	if (rat->x <= WINDOW_WIDTH && rat->y < WINDOW_HEIGHT && rat->y >= 0
		&& rat->x >= 0)
	{
		if (rat->color == -2)
			mlx_put_pixel(main.img, rat->x, rat->y, get_rgba(218, 247, 166,
					255));
		else if (rat->color == -1)
			mlx_put_pixel(main.img, rat->x, rat->y, get_rgba(100, 149, 237,
					255));
		else if (rat->color == 2)
			mlx_put_pixel(main.img, rat->x, rat->y, get_rgba(64, 224, 208,
					255));
		else if (rat->color == 1)
			mlx_put_pixel(main.img, rat->x, rat->y, get_rgba(199, 0, 57, 255));
		else
			mlx_put_pixel(main.img, rat->x, rat->y, get_rgba(88, 24, 69, 255));
	}
}

void	ft_trace_line(int mod, t_coor *mat_coor, t_rat *rat, t_main main)
{
	int	e_temp;

	ft_declaration_rat(mod, mat_coor, rat);
	while (rat->x != (int)mat_coor[mod].x2 || rat->y != (int)mat_coor[mod].y2)
	{
		ft_check_frame(rat, main);
		e_temp = rat->e * 2;
		if (e_temp > -rat->dy)
		{
			rat->e -= rat->dy;
			if ((int)mat_coor[mod].x2 > (int)mat_coor[mod].x1)
				rat->x += 1;
			else
				rat->x -= 1;
		}
		else
		{
			rat->e += rat->dx;
			if ((int)mat_coor[mod].y2 > (int)mat_coor[mod].y1)
				rat->y += 1;
			else
				rat->y -= 1;
		}
	}
}

void	ft_declaration_rat(int mod, t_coor *mat_coor, t_rat *rat)
{
	rat->dx = abs((int)mat_coor[mod].x2 - (int)mat_coor[mod].x1);
	rat->dy = abs((int)mat_coor[mod].y2 - (int)mat_coor[mod].y1);
	rat->e = rat->dx - rat->dy;
	rat->x = (int)mat_coor[mod].x1;
	rat->y = (int)mat_coor[mod].y1;
}
