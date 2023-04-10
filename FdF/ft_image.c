/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:32:55 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/10 15:23:47 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    ft_check_frame(t_rat *rat, t_main main)
{
    if (rat->x <= WINDOW_WIDTH && rat->y <= WINDOW_HEIGHT)
    {
        if (rat->color == -2)
            my_mlx_pixel_put(&main.img, rat->x, rat->y, GREEN_PIXEL);
        else if (rat->color == -1)
            my_mlx_pixel_put(&main.img, rat->x, rat->y, BLUE_PIXEL);
        else if (rat->color == 2)
            my_mlx_pixel_put(&main.img, rat->x, rat->y, LIGHT_BLUE_PIXEL);
        else if (rat->color == 1)
            my_mlx_pixel_put(&main.img, rat->x, rat->y, RED_PIXEL);
        else
            my_mlx_pixel_put(&main.img, rat->x, rat->y, DARK_RED_PIXEL);
    }
}

