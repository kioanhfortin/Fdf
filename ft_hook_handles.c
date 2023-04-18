/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_handles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:09:57 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 16:28:44 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	re_img(t_main *main)
{
	mlx_delete_image(main->mlx, main->img);
	main->img = mlx_new_image(main->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_fill_coor_hori(main);
	ft_fill_coor_vert(main);
	mlx_image_to_window(main->mlx, main->img, 0, 0);
}

void	handle_keyboard(mlx_key_data_t keydata, void *param)
{
	t_main	*main;

	main = (t_main *)param;
	(void)keydata;
	if (mlx_is_key_down(main->mlx, MLX_KEY_ESCAPE))
		exit(0);
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
	handle_keyboard_2(main);
}

void	handle_keyboard_2(t_main *main)
{
	if (mlx_is_key_down(main->mlx, MLX_KEY_Q))
		depth_re(main);
	if (mlx_is_key_down(main->mlx, MLX_KEY_KP_1))
		ft_change_view_45(main);
	if (mlx_is_key_down(main->mlx, MLX_KEY_KP_2))
		ft_change_view_up(main);
	if (mlx_is_key_down(main->mlx, MLX_KEY_RIGHT))
		ft_angle_plus(main);
	if (mlx_is_key_down(main->mlx, MLX_KEY_LEFT))
		ft_angle_minus(main);
	if (mlx_is_key_down(main->mlx, MLX_KEY_DOWN))
		ft_angle_re(main);
	if (mlx_is_key_down(main->mlx, MLX_KEY_V))
		ft_rot_plus(main);
	if (mlx_is_key_down(main->mlx, MLX_KEY_F))
		ft_rot_minus(main);
	if (mlx_is_key_down(main->mlx, MLX_KEY_R))
		ft_rot_re(main);
}

void	handle_mouse(mouse_key_t button, action_t action, modifier_key_t mods,
		void *param)
{
	t_main	*main;

	main = (t_main *)param;
	(void)mods;
	(void)action;
	if (button == 0)
		zoom_in(main);
	if (button == 1)
		zoom_out(main);
}
