/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_hamdles_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:26:30 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 16:26:44 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	y_re_translation(t_main *main)
{
	main->mat.trans_y = 0;
	re_img(main);
}

void	*ft_exit(t_main *main)
{
	if (main->mat.mat)
		ft_free_tab2((void **)main->mat.mat);
	exit(0);
}

void	ft_rot_plus(t_main *main)
{
	main->mat.rot += 1;
	re_img(main);
}

void	ft_rot_minus(t_main *main)
{
	main->mat.rot -= 1;
	re_img(main);
}

void	ft_rot_re(t_main *main)
{
	main->mat.rot = 0;
	re_img(main);
}
