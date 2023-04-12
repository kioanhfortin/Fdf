/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_to_screen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:31:51 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/10 18:59:40 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int x_translation(int keycode, t_mat *mat, t_main main, t_rat *rat)
{
    if (keycode == 120)
    {
        printf("%d\n", keycode);
        mat->trans_x += 100;
        ft_fill_coor_hori(rat, mat, main);
        mlx_put_image_to_window(main.mlx, main.mlx_win, main.img.img, 0, 0);
        return (1);
    }
    return (0);
}

int handle_input(int keyCode)
{
    if (keyCode == 53)
        exit (0);
    return (0);
}

int my_loop_function(t_main *main)
{
    (void)main;
    return (0);
}