/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_handles_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:50:46 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 14:00:18 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_plus_translation(t_main *main)
{
	main->mat.trans_x += 20;
	re_img(main);
}

void	x_minus_translation(t_main *main)
{
	main->mat.trans_x -= 20;
	re_img(main);
}

void	x_re_translation(t_main *main)
{
	main->mat.trans_x = 0;
	re_img(main);
}

void	y_plus_translation(t_main *main)
{
	main->mat.trans_y += 20;
	re_img(main);
}

void	y_minus_translation(t_main *main)
{
	main->mat.trans_y -= 20;
	re_img(main);
}
