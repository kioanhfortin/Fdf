/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_handles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:09:57 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/13 15:07:19 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void    ft_modif_handler(t_main main, t_rat *rat, t_mat *mat)
// {
    // (void)rat;
    // (void)mat;
    // mlx_clear_window(main.mlx, main.mlx_win);
    // mlx_key_hook(main.mlx_win, &x_translation, NULL);
    // mlx_destroy_window(main.mlx, main.mlx_win);
    // mlx_key_hook(main.mlx_win, &handle_input, NULL);
    // x_translation(keycode, mat, main, rat)
    // ft_fill_coor_hori(rat, mat, main);
// }

void re_img(t_main  *main)
{
    mlx_delete_image(main->mlx, main->img);
    main->img = mlx_new_image(main->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    ft_fill_coor_hori(main);
    ft_fill_coor_vert(main);
    mlx_image_to_window(main->mlx, main->img, 0, 0);
}

void x_plus_translation(t_main *main)
{
    main->mat.trans_x += 20;
    re_img(main);
}

void x_minus_translation(t_main *main)
{
    main->mat.trans_x -= 20;
    re_img(main);
}

void x_re_translation(t_main *main)
{
    main->mat.trans_x = 0;
    re_img(main);
}

void y_plus_translation(t_main *main)
{
    main->mat.trans_y += 20;
    re_img(main);
}

void y_minus_translation(t_main *main)
{
    main->mat.trans_y -= 20;
    re_img(main);
}

void y_re_translation(t_main *main)
{
    main->mat.trans_y = 0;
    re_img(main);
}

void depth_plus(t_main *main)
{
    main->mat.depth += 1;
    re_img(main);
}

void depth_minus(t_main *main)
{
    main->mat.depth -= 1;
    re_img(main);
}

void depth_re(t_main *main)
{
    main->mat.depth = 0;
    re_img(main);
}

void handle_input(mlx_key_data_t keydata, void *param)
{
    t_main *main;

    main = (t_main *)param;
    (void)keydata;
    if (mlx_is_key_down(main->mlx, MLX_KEY_ESCAPE))
        exit (0);
    if (mlx_is_key_down(main->mlx, MLX_KEY_X))
        x_plus_translation(main);
    if (mlx_is_key_down(main->mlx, MLX_KEY_S))
        x_minus_translation(main);
    if (mlx_is_key_down(main->mlx, MLX_KEY_W))
        x_re_translation(main);
    if (mlx_is_key_down(main->mlx, MLX_KEY_C))
        y_plus_translation(main);
    if (mlx_is_key_down(main->mlx, MLX_KEY_D))
        y_minus_translation(main);
    if (mlx_is_key_down(main->mlx, MLX_KEY_E))
        y_re_translation(main);
    if (mlx_is_key_down(main->mlx, MLX_KEY_Z))
        depth_plus(main);
    if (mlx_is_key_down(main->mlx, MLX_KEY_A))
        depth_minus(main);
    if (mlx_is_key_down(main->mlx, MLX_KEY_Q))
        depth_re(main);
}