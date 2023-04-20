/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:58:27 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/19 17:36:20 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clean_rat(t_main *main)
{
	main->rat.x = 0;
	main->rat.x1 = 0;
	main->rat.x2 = 0;
	main->rat.y = 0;
	main->rat.y1 = 0;
	main->rat.y2 = 0;
	main->rat.dx = 0;
	main->rat.dy = 0;
	main->rat.color = 0;
}

void	ft_init_struct(t_mat *mat)
{
	mat->size_x = 0;
	mat->size_y = 0;
	mat->center_x = 0;
	mat->center_y = 0;
	mat->deg = 60;
	mat->rad = 0;
	mat->rot = 0;
	mat->rot_rad = 0;
	mat->zoom = 30;
	mat->depth = 0;
	mat->trans_x = 0;
	mat->type_view = 2;
}

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_c_is_alpha(char *str, int i)
{
	if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
		return (0);
	return (1);
}
