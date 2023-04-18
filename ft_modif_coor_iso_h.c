/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_coor_iso_h.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:09:25 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 16:35:27 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_vue_iso_h(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = x + cos(main->mat.rad) * main->mat.mat[y][x]
		- cos(main->mat.rad) * y;
	main->mat_coor[mod].y1 = y * sin(main->mat.rad) - main->mat.mat[y][x]
		* sin(main->mat.rad);
	x++;
	if (x >= main->mat.size_x)
		return ;
	main->mat_coor[mod].x2 = x + cos(main->mat.rad) * main->mat.mat[y][x]
		- cos(main->mat.rad) * y;
	main->mat_coor[mod].y2 = y * sin(main->mat.rad) - main->mat.mat[y][x]
		* sin(main->mat.rad);
	ft_modif_affichage(main, x, y, mod);
}

void	ft_depth_iso_h(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = x + cos(main->mat.rad) * (main->mat.mat[y][x]
			+ main->mat.depth) - cos(main->mat.rad) * y;
	main->mat_coor[mod].y1 = y * sin(main->mat.rad) - (main->mat.mat[y][x]
			+ main->mat.depth) * sin(main->mat.rad);
	x++;
	if (x >= main->mat.size_x)
		return ;
	main->mat_coor[mod].x2 = x + cos(main->mat.rad) * (main->mat.mat[y][x]
			+ main->mat.depth) - cos(main->mat.rad) * y;
	main->mat_coor[mod].y2 = y * sin(main->mat.rad) - (main->mat.mat[y][x]
			+ main->mat.depth) * sin(main->mat.rad);
	ft_modif_affichage(main, x, y, mod);
}

void	ft_depth_iso_h1(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = x + cos(main->mat.rad) * main->mat.mat[y][x]
		- cos(main->mat.rad) * y;
	main->mat_coor[mod].y1 = y * sin(main->mat.rad) - main->mat.mat[y][x]
		* sin(main->mat.rad);
	x++;
	if (x >= main->mat.size_x)
		return ;
	main->mat_coor[mod].x2 = x + cos(main->mat.rad) * (main->mat.mat[y][x]
			+ main->mat.depth) - cos(main->mat.rad) * y;
	main->mat_coor[mod].y2 = y * sin(main->mat.rad) - (main->mat.mat[y][x]
			+ main->mat.depth) * sin(main->mat.rad);
	ft_modif_affichage(main, x, y, mod);
}

void	ft_depth_iso_h2(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = x + cos(main->mat.rad) * (main->mat.mat[y][x]
			+ main->mat.depth) - cos(main->mat.rad) * y;
	main->mat_coor[mod].y1 = y * sin(main->mat.rad) - (main->mat.mat[y][x]
			+ main->mat.depth) * sin(main->mat.rad);
	x++;
	if (x >= main->mat.size_x)
		return ;
	main->mat_coor[mod].x2 = x + cos(main->mat.rad) * main->mat.mat[y][x]
		- cos(main->mat.rad) * y;
	main->mat_coor[mod].y2 = y * sin(main->mat.rad) - main->mat.mat[y][x]
		* sin(main->mat.rad);
	ft_modif_affichage(main, x, y, mod);
}
