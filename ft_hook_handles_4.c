/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_handles_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:24:38 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 16:25:19 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_change_view_45(t_main *main)
{
	main->mat.type_view = 2;
	re_img(main);
}

void	ft_change_view_up(t_main *main)
{
	main->mat.type_view = 1;
	re_img(main);
}

void	ft_angle_plus(t_main *main)
{
	main->mat.deg += 1;
	re_img(main);
}

void	ft_angle_minus(t_main *main)
{
	main->mat.deg -= 1;
	re_img(main);
}

void	ft_angle_re(t_main *main)
{
	main->mat.deg = 60;
	re_img(main);
}
