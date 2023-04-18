/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_v.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:16:25 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 17:25:46 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_coor_vert(t_main *main)
{
	int	x;
	int	y;
	int	mod;

	x = 0;
	y = 0;
	mod = 0;
	main->rat.flag = 0;
	while (x < main->mat.size_x)
	{
		while (y < main->mat.size_y)
		{
			if (y + 1 >= main->mat.size_y)
				break ;
			if (main->mat.type_view == 2)
				ft_vue_isometrique_v(main, y, x, mod);
			else
				ft_vue_hauteur_v(main, y, x, mod);
			y++;
			mod++;
		}
		mod++;
		y = 0;
		x++;
	}
}

void	ft_vue_isometrique_v(t_main *main, int y, int x, int mod)
{
	if (main->mat.mat[y][x] != 0 && main->mat.mat[y + 1][x] != 0)
		ft_depth_iso_v(main, y, x, mod);
	else if (main->mat.mat[y][x] == 0 && main->mat.mat[y + 1][x] != 0)
		ft_depth_iso_v1(main, y, x, mod);
	else if (main->mat.mat[y][x] != 0 && main->mat.mat[y + 1][x] == 0)
		ft_depth_iso_v2(main, y, x, mod);
	else
		ft_vue_iso_v(main, y, x, mod);
}

void	ft_vue_hauteur_v(t_main *main, int y, int x, int mod)
{
	if (main->mat.mat[y][x] != 0 && main->mat.mat[y + 1][x] != 0)
		ft_depth_modifier_v(main, y, x, mod);
	else if (main->mat.mat[y][x] == 0 && main->mat.mat[y + 1][x] != 0)
		ft_depth_modifier_v1(main, y, x, mod);
	else if (main->mat.mat[y][x] != 0 && main->mat.mat[y + 1][x] == 0)
		ft_depth_modifier_v2(main, y, x, mod);
	else
		ft_normal_v(main, y, x, mod);
}
