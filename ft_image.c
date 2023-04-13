/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:32:55 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/12 18:53:21 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void    ft_check_frame(t_rat *rat, t_main main)
{
    if (rat->x <= WINDOW_WIDTH && rat->y <= WINDOW_HEIGHT)
    {
        if (rat->color == -2)
            mlx_put_pixel(main.img, rat->x, rat->y, get_rgba(218, 247, 166, 255));
        else if (rat->color == -1)
            mlx_put_pixel(main.img, rat->x, rat->y, get_rgba(100, 149, 237, 255));
        else if (rat->color == 2)
            mlx_put_pixel(main.img, rat->x, rat->y, get_rgba(64, 224, 208, 255));
        else if (rat->color == 1)
            mlx_put_pixel(main.img, rat->x, rat->y, get_rgba(199, 0, 57, 255));
        else
            mlx_put_pixel(main.img, rat->x, rat->y, get_rgba(88, 24, 69, 255));
    }
}

