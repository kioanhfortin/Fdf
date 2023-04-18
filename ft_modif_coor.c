/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_coor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:20:04 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 17:12:09 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coor	*ft_rotate_coor(t_coor *mat_coor, t_mat *mat, int mod)
{
	double	cos_thet;
	double	sin_thet;
	double	rot_mat[2][2];

	mat->rot_rad = ft_deg_rad(mat->rot);
	cos_thet = cos(mat->rot_rad);
	sin_thet = sin(mat->rot_rad);
	rot_mat[0][0] = cos_thet;
	rot_mat[0][1] = -sin_thet;
	rot_mat[1][0] = sin_thet;
	rot_mat[1][1] = cos_thet;
	mat_coor->temp_x = mat_coor[mod].x1;
	mat_coor->temp_y = mat_coor[mod].y1;
	mat_coor->rot_x = (mat_coor->temp_x * rot_mat[0][0]) + (mat_coor->temp_y
			* rot_mat[0][1]);
	mat_coor->rot_y = (mat_coor->temp_x * rot_mat[1][0]) + (mat_coor->temp_y
			* rot_mat[1][1]);
	mat_coor = ft_rotate_coor_2(mat_coor, mod);
	mat_coor->rot_x = (mat_coor->temp_x * rot_mat[0][0]) + (mat_coor->temp_y
			* rot_mat[0][1]);
	mat_coor->rot_y = (mat_coor->temp_x * rot_mat[1][0]) + (mat_coor->temp_y
			* rot_mat[1][1]);
	mat_coor[mod].x2 = mat_coor->rot_x;
	mat_coor[mod].y2 = mat_coor->rot_y;
	return (mat_coor);
}

t_coor	*ft_rotate_coor_2(t_coor *mat_coor, int mod)
{
	mat_coor[mod].x1 = mat_coor->rot_x;
	mat_coor[mod].y1 = mat_coor->rot_y;
	mat_coor->temp_x = mat_coor[mod].x2;
	mat_coor->temp_y = mat_coor[mod].y2;
	return (mat_coor);
}

void	ft_modif_affichage(t_main *main, int x, int y, int mod)
{
	main->mat_coor = ft_rotate_coor(main->mat_coor, &main->mat, mod);
	main->mat_coor[mod].x1 = main->mat_coor[mod].x1 * main->mat.zoom
		+ main->mat.center_x + main->mat.trans_x;
	main->mat_coor[mod].y1 = main->mat_coor[mod].y1 * main->mat.zoom
		+ main->mat.center_y + main->mat.trans_y;
	main->mat_coor[mod].x2 = main->mat_coor[mod].x2 * main->mat.zoom
		+ main->mat.center_x + main->mat.trans_x;
	main->mat_coor[mod].y2 = main->mat_coor[mod].y2 * main->mat.zoom
		+ main->mat.center_y + main->mat.trans_y;
	main->rat = *ft_color(&main->rat, &main->mat, x, y);
	ft_trace_line(mod, main->mat_coor, &main->rat, *main);
	ft_clean_rat(main);
}
