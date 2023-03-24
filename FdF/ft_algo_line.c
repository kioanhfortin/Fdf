/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:46:50 by kfortin           #+#    #+#             */
/*   Updated: 2023/03/23 16:21:47 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void     ft_trace_seg(t_rat *rat, t_main main)
{
    rat->dy = rat->y2 - rat->y1;
    rat->dx = rat->x2 - rat->x1;
    rat->y = rat->y1; //rangée initiale
    rat->x = rat->x1;
    rat->e = -rat->dx; //valeur initiale d'erreur
    rat->e10 = rat->dy * 2;
    rat->e01 = -rat->dx * 2;
    while (rat->x <= rat->x2)
    {
        ft_trace_pixel(rat->x, rat->y, main);
        if (rat->e + rat->e10 >= 0)
        {
            rat->y++;
            rat->e = rat->e + rat->e01;
        }
        rat->x++;
    }
}