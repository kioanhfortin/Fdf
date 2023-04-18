/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_coor_hau_v.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:38:05 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 16:38:29 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_normal_v(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
	main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
	y++;
	if (y >= main->mat.size_y)
		return ;
	main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
	main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
	ft_modif_affichage(main, x, y, mod);
}

void	ft_depth_modifier_v(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	y++;
	if (y >= main->mat.size_y)
		return ;
	main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	ft_modif_affichage(main, x, y, mod);
}

void	ft_depth_modifier_v1(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
	main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
	y++;
	if (y >= main->mat.size_y)
		return ;
	main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	ft_modif_affichage(main, x, y, mod);
}

void	ft_depth_modifier_v2(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	y++;
	if (y >= main->mat.size_y)
		return ;
	main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
	main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
	ft_modif_affichage(main, x, y, mod);
}
