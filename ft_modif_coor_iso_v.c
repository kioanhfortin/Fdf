/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_coor_iso_v.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:32:45 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 16:35:16 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_vue_iso_v(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = x + cos(main->mat.rad) * (main->mat.mat[y][x])
		- cos(main->mat.rad) * y;
	main->mat_coor[mod].y1 = y * sin(main->mat.rad) - (main->mat.mat[y][x])
		* sin(main->mat.rad);
	y++;
	if (y >= main->mat.size_y)
		return ;
	main->mat_coor[mod].x2 = x + cos(main->mat.rad) * (main->mat.mat[y][x])
		- cos(main->mat.rad) * y;
	main->mat_coor[mod].y2 = y * sin(main->mat.rad) - (main->mat.mat[y][x])
		* sin(main->mat.rad);
	ft_modif_affichage(main, x, y, mod);
}

void	ft_depth_iso_v(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = x + cos(main->mat.rad) * (main->mat.mat[y][x]
			+ main->mat.depth) - cos(main->mat.rad) * y;
	main->mat_coor[mod].y1 = y * sin(main->mat.rad) - (main->mat.mat[y][x]
			+ main->mat.depth) * sin(main->mat.rad);
	y++;
	if (y >= main->mat.size_y)
		return ;
	main->mat_coor[mod].x2 = x + cos(main->mat.rad) * (main->mat.mat[y][x]
			+ main->mat.depth) - cos(main->mat.rad) * y;
	main->mat_coor[mod].y2 = y * sin(main->mat.rad) - (main->mat.mat[y][x]
			+ main->mat.depth) * sin(main->mat.rad);
	ft_modif_affichage(main, x, y, mod);
}

void	ft_depth_iso_v1(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = x + cos(main->mat.rad) * (main->mat.mat[y][x])
		- cos(main->mat.rad) * y;
	main->mat_coor[mod].y1 = y * sin(main->mat.rad) - (main->mat.mat[y][x])
		* sin(main->mat.rad);
	y++;
	if (y >= main->mat.size_y)
		return ;
	main->mat_coor[mod].x2 = x + cos(main->mat.rad) * (main->mat.mat[y][x]
			+ main->mat.depth) - cos(main->mat.rad) * y;
	main->mat_coor[mod].y2 = y * sin(main->mat.rad) - (main->mat.mat[y][x]
			+ main->mat.depth) * sin(main->mat.rad);
	ft_modif_affichage(main, x, y, mod);
}

void	ft_depth_iso_v2(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = x + cos(main->mat.rad) * (main->mat.mat[y][x]
			+ main->mat.depth) - cos(main->mat.rad) * y;
	main->mat_coor[mod].y1 = y * sin(main->mat.rad) - (main->mat.mat[y][x]
			+ main->mat.depth) * sin(main->mat.rad);
	y++;
	if (y >= main->mat.size_y)
		return ;
	main->mat_coor[mod].x2 = x + cos(main->mat.rad) * (main->mat.mat[y][x])
		- cos(main->mat.rad) * y;
	main->mat_coor[mod].y2 = y * sin(main->mat.rad) - (main->mat.mat[y][x])
		* sin(main->mat.rad);
	ft_modif_affichage(main, x, y, mod);
}
