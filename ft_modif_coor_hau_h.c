/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_coor_hau_h.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:36:34 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 16:37:10 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_normal_h(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
	main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
	x++;
	if (x >= main->mat.size_x)
		return ;
	main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
	main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
	ft_modif_affichage(main, x, y, mod);
}

void	ft_depth_modifier_h(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	x++;
	if (x >= main->mat.size_x)
		return ;
	main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	ft_modif_affichage(main, x, y, mod);
}

void	ft_depth_modifier_h1(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
	main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
	x++;
	if (x >= main->mat.size_x)
		return ;
	main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	ft_modif_affichage(main, x, y, mod);
}

void	ft_depth_modifier_h2(t_main *main, int y, int x, int mod)
{
	main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x]
					+ main->mat.depth)));
	x++;
	if (x >= main->mat.size_x)
		return ;
	main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
	main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
	ft_modif_affichage(main, x, y, mod);
}
