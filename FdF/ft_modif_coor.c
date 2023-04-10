/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_coor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:20:04 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/10 16:30:40 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coor *ft_rotate_coor(t_coor *mat_coor, t_rat *rat, t_mat *mat, int mod)
{
    int cos_thet;
    int sin_thet;
    int rot_mat[2][2];
    int i;
    int temp_x = 0;
    int temp_y = 0;
    int rot_x;
    int rot_y;

    (void)rat;
    // (void)mat;
    mat->rot_rad = ft_deg_rad(mat->rot);
    cos_thet = cos(mat->rot_rad) * 1000;
    sin_thet = sin(mat->rot_rad) * 1000;
    rot_mat[0][0] = cos_thet / 1000;
    rot_mat[0][1] = -sin_thet / 1000;
    rot_mat[1][0] = sin_thet / 1000;
    rot_mat[1][1] = cos_thet / 1000;
    mat->center_map_x = WINDOW_WIDTH / 2;
    mat->center_map_y = WINDOW_HEIGHT / 2;
    i = 0;
    // while (i < 3)
    // {
        rot_x = 0;
        rot_x = 0;
        temp_x = mat_coor[mod].x1;
        temp_y = mat_coor[mod].y1;
        rot_x = (temp_x * rot_mat[0][0]) + (temp_y * rot_mat[0][1]);
        rot_y = (temp_x * rot_mat[1][0]) + (temp_y * rot_mat[1][1]);
        mat_coor[mod].x1 = rot_x + -mat->center_map_x;
        mat_coor[mod].y1 = rot_y + -mat->center_map_y;
        rot_x = 0;
        rot_x = 0;
        temp_x = mat_coor[mod].x2;
        temp_y = mat_coor[mod].y2;
        rot_x = (temp_x * rot_mat[0][0]) + (temp_y * rot_mat[0][1]);
        rot_y = (temp_x * rot_mat[1][0]) + (temp_y * rot_mat[1][1]);
        mat_coor[mod].x2 = rot_x + -mat->center_map_x;
        mat_coor[mod].y2 = rot_y + -mat->center_map_y;
        printf("x1 :%d, y1 :%d, x2 :%d, y2 : %d", mat_coor[mod].x1, mat_coor[mod].y1, mat_coor[mod].x2, mat_coor[mod].y2);
    //     i++;
    // }
    return (mat_coor);
}
int **ft_modif_depth(t_mat *mat)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (y < mat->size_y)
    {
        while (x < mat->size_x)
        {
            if (mat->mat[y][x] != 0)
                mat->mat[y][x] = mat->mat[y][x] + mat->depth;
            x++;
        }
        x = 0;
        y++;
    }
    return (mat->mat);
}
