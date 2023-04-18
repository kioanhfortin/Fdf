/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_h.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:13:29 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 17:26:46 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_coor_hori(t_main *main)
{
	int	x;
	int	y;
	int	mod;

	x = 0;
	y = 0;
	mod = 0;
	main->rat.flag = 1;
	ft_center(main);
	main->mat.rad = ft_deg_rad(main->mat.deg);
	while (y < main->mat.size_y)
	{
		while (x < main->mat.size_x)
		{
			if (x + 1 >= main->mat.size_x)
				break ;
			ft_fill_coor_hori_2(main, mod, x, y);
			mod++;
			x++;
		}
		mod++;
		x = 0;
		y++;
	}
}

void	ft_fill_coor_hori_2(t_main *main, int mod, int x, int y)
{
	if (main->mat.type_view == 2)
		ft_vue_isometrique_h(main, y, x, mod);
	else
		ft_vue_hauteur_h(main, y, x, mod);
}

void	ft_vue_hauteur_h(t_main *main, int y, int x, int mod)
{
	if (main->mat.mat[y][x] != 0 && main->mat.mat[y][x + 1] != 0)
		ft_depth_modifier_h(main, y, x, mod);
	else if (main->mat.mat[y][x] == 0 && main->mat.mat[y][x + 1] != 0)
		ft_depth_modifier_h1(main, y, x, mod);
	else if (main->mat.mat[y][x] != 0 && main->mat.mat[y][x + 1] == 0)
		ft_depth_modifier_h2(main, y, x, mod);
	else
		ft_normal_h(main, y, x, mod);
}

void	ft_vue_isometrique_h(t_main *main, int y, int x, int mod)
{
	if (main->mat.mat[y][x] != 0 && main->mat.mat[y][x + 1] != 0)
		ft_depth_iso_h(main, y, x, mod);
	else if (main->mat.mat[y][x] == 0 && main->mat.mat[y][x + 1] != 0)
		ft_depth_iso_h1(main, y, x, mod);
	else if (main->mat.mat[y][x] != 0 && main->mat.mat[y][x + 1] == 0)
		ft_depth_iso_h2(main, y, x, mod);
	else
		ft_vue_iso_h(main, y, x, mod);
}
