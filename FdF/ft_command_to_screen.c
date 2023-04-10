/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_to_screen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:31:51 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/10 18:03:47 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int my_loop_function(int keycode, t_mat *mat, t_main main, t_rat *rat)
{
    if (keycode)
    {
        printf("%d\n", keycode);
        mat->trans_x += 100;
        ft_fill_coor_hori(rat, mat, main);
        mlx_put_image_to_window(main.mlx, main.mlx_win, main.img.img, 0, 0);
        return (1);
    }
    return (0);
}