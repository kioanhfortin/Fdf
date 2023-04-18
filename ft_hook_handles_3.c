/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_handles_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:00:47 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 16:25:49 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	depth_plus(t_main *main)
{
	main->mat.depth += 1;
	re_img(main);
}

void	depth_minus(t_main *main)
{
	main->mat.depth -= 1;
	re_img(main);
}

void	depth_re(t_main *main)
{
	main->mat.depth = 0;
	re_img(main);
}

void	zoom_in(t_main *main)
{
	main->mat.zoom += 1;
	re_img(main);
}

void	zoom_out(t_main *main)
{
	main->mat.zoom -= 1;
	re_img(main);
}
