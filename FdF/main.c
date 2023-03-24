/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:47:16 by kfortin           #+#    #+#             */
/*   Updated: 2023/03/23 15:58:34 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int render_rect(t_data *data, t_rect rect)
{
    int i;
    int j;

    // if (data->win_ptr == NULL)
    //     return (1);
    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            my_mlx_pixel_put(data, j++, i, rect.color);/
        i++;
    }
    return (0);
}

void    render_background(t_data *data, int color)
{
    int i;
    int j;

    // if (data->win_ptr == NULL)
    //     return ;
    i = 0;
    while (i < WINDOW_HEIGHT)
    {
        j = 0;
        while(j < WINDOW_WIDTH)
            my_mlx_pixel_put(data, j++, i, color);
        ++i;
    }
}

int render(t_data *data)
{
    render_background(data, LIGHT_GREEN_PIXEL);
    render_rect(data, ((t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL}));
    render_rect(data, ((t_rect){0, 0, 100, 100, RED_PIXEL}));
    return (0);
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
    img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    my_mlx_pixel_put(&img, 5, 5, 0x009FE2BF);
    // render(&img);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}