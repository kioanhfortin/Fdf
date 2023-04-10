/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:46:50 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/07 15:53:42 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void    ft_trace_line(t_rat *rat, t_main main)
// {
//     ft_trace_HB_GD(rat, main);
    // if ((rat->x1 < rat->x2) && (rat->y1 < rat->y2))
    //     ft_trace_HB_GD(rat, main);
    // else if ((rat->x1 > rat->x2) && (rat->y1 < rat->y2))
    //     ft_trace_HB_DG(rat, main);
    // else if ((rat->x1 < rat->x2) && (rat->y1 > rat->y2))
    //     ft_trace_HB_GD(rat, main);
    // else if ((rat->x1 > rat->x2) && (rat->y1 > rat->y2))
    //     ft_trace_BH_DG(rat, main);
// }

// GOOD ONE
// void     ft_trace_HB_GD(t_rat *rat, t_main main)
// {
//     int e_temp;
    
//     rat->dx = abs(rat->x2 - rat->x1);
//     rat->dy = abs(rat->y2 - rat->y1); //rangée initiale
//     rat->e = rat->dx - rat->dy;
//     rat->x = rat->x1;
//     rat->y = rat->y1;
//     while (rat->x != rat->x2 || rat->y != rat->y2)
//     {
//         ft_check_frame(rat, main);
//         e_temp = rat->e * 2;
//         if (e_temp > -rat->dy)
//         {
//             rat->e -= rat->dy;
//             rat->x += (rat->x2 > rat->x1) ? 1 : -1;
//         }
//         else
//         {
//             rat->e += rat->dx;
//             rat->y += (rat->y2 > rat->y1) ? 1 : -1;
//         }
//     }
// }

// void     ft_trace_line(t_rat *rat, t_main main)
// {
//     int e_temp;
    
//     rat->dx = abs(rat->x2 - rat->x1);
//     rat->dy = abs(rat->y2 - rat->y1); //rangée initiale
//     rat->e = rat->dx - rat->dy;
//     rat->x = rat->x1;
//     rat->y = rat->y1;
//     while (rat->x != rat->x2 || rat->y != rat->y2)
//     {
//         ft_check_frame(rat, main);
//         e_temp = rat->e * 2;
//         if (e_temp > -rat->dy)
//         {
//             rat->e -= rat->dy;
//             if (rat->x2 > rat->x1)
//                 rat->x += 1;
//             else
//                 rat->x -= 1;
//         }
//         else
//         {
//             rat->e += rat->dx;
//             if (rat->y2 > rat->y1)
//                 rat->y += 1;
//             else
//                 rat->y -= 1;
//         }
//     }
// }

void     ft_trace_line(int mod, t_coor *mat_coor, t_rat *rat, t_main main)
{
    int e_temp;
    
    rat->dx = abs(mat_coor[mod].x2 - mat_coor[mod].x1);
    rat->dy = abs(mat_coor[mod].y2 - mat_coor[mod].y1); //rangée initiale
    rat->e = rat->dx - rat->dy;
    rat->x = mat_coor[mod].x1;
    rat->y = mat_coor[mod].y1;
    while (rat->x != mat_coor[mod].x2 || rat->y != mat_coor[mod].y2)
    {
        ft_check_frame(rat, main);
        e_temp = rat->e * 2;
        if (e_temp > -rat->dy)
        {
            rat->e -= rat->dy;
            if (mat_coor[mod].x2 > mat_coor[mod].x1)
                rat->x += 1;
            else
                rat->x -= 1;
        }
        else
        {
            rat->e += rat->dx;
            if (mat_coor[mod].y2 > mat_coor[mod].y1)
                rat->y += 1;
            else
                rat->y -= 1;
        }
    }
}

// void     ft_trace_HB_DG(t_rat *rat, t_main main)
// {
//     rat->dy = rat->y2 - rat->y1;
//     rat->dx = rat->x2 - rat->x1;
//     rat->y = rat->y1;
//     rat->x = rat->x1;
//     while (rat->x > rat->x2)
//     {
//         ft_check_frame(rat, main);
//         if (((2 * rat->dy) - rat->dx) >= 0)
//             rat->y++;
//         rat->x--;
//     }
// }

void     ft_trace_BH_GD(t_rat *rat, t_main main)
{
    rat->dy = rat->y2 - rat->y1;
    rat->dx = rat->x2 - rat->x1;
    rat->y = rat->y1;
    rat->x = rat->x1;
    while (rat->x < rat->x2)
    {
        ft_check_frame(rat, main);
        if (((2 * rat->dy) - rat->dx) <= 0)
            rat->y--;
        rat->x++;
    }
}

void     ft_trace_BH_DG(t_rat *rat, t_main main)
{
    rat->dy = rat->y2 - rat->y1;
    rat->dx = rat->x2 - rat->x1;
    rat->y = rat->y1;
    rat->x = rat->x1;
    while (rat->x > rat->x2)
    {
        ft_check_frame(rat, main);
        if (((2 * rat->dy) - rat->dx) <= 0)
            rat->y--;
        rat->x--;
    }
}