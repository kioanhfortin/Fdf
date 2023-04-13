/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_coor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:20:04 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/13 15:26:14 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coor *ft_rotate_coor(t_coor *mat_coor, t_mat *mat, int mod)
{
    double cos_thet;
    double sin_thet;
    double rot_mat[2][2];
    double temp_x = 0;
    double temp_y = 0;
    double rot_x;
    double rot_y;

    mat->rot_rad = ft_deg_rad(mat->rot);
    cos_thet = cos(mat->rot_rad);
    sin_thet = sin(mat->rot_rad);
    rot_mat[0][0] = cos_thet;
    rot_mat[0][1] = -sin_thet;
    rot_mat[1][0] = sin_thet;
    mat->center_map_x = WINDOW_WIDTH / 2;
    rot_mat[1][1] = cos_thet;
    mat->center_map_y = WINDOW_HEIGHT / 2;
    temp_x = mat_coor[mod].x1;
    temp_y = mat_coor[mod].y1;
    rot_x = (temp_x * rot_mat[0][0]) + (temp_y * rot_mat[0][1]);
    rot_y = (temp_x * rot_mat[1][0]) + (temp_y * rot_mat[1][1]);
    mat_coor[mod].x1 = rot_x;
    mat_coor[mod].y1 = rot_y;
    temp_x = mat_coor[mod].x2;
    temp_y = mat_coor[mod].y2;
    rot_x = (temp_x * rot_mat[0][0]) + (temp_y * rot_mat[0][1]);
    rot_y = (temp_x * rot_mat[1][0]) + (temp_y * rot_mat[1][1]);
    mat_coor[mod].x2 = rot_x;
    mat_coor[mod].y2 = rot_y;
    return (mat_coor);
}

int **ft_modif_depth(t_mat *mat)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    //improve ne pas modifier les valeur de la map initiale
    while (y < mat->size_y)
    {
        while (x < mat->size_x)
        {
            
            if (mat->mat[y][x] != 0)
            {
                if (mat->mat[y][x] + mat->depth == 0)
                    mat->mat[y][x] += 2;
                if (mat->mat[y][x] - mat->depth == 0)
                    mat->mat[y][x] -= 2;
                else
                    mat->mat[y][x] += mat->depth;
            }
            x++;
        }
        x = 0;
        y++;
    }
    return (mat->mat);
}

void    ft_modif_affichage(t_main *main, int x, int y, int mod)
{
    main->mat_coor = ft_rotate_coor(main->mat_coor, &main->mat, mod);
    main->mat_coor[mod].x1 = main->mat_coor[mod].x1 * main->mat.zoom + main->mat.center_x + main->mat.trans_x;
    main->mat_coor[mod].y1 = main->mat_coor[mod].y1 * main->mat.zoom + main->mat.center_y + main->mat.trans_y;
    main->mat_coor[mod].x2 = main->mat_coor[mod].x2 * main->mat.zoom + main->mat.center_x + main->mat.trans_x;
    main->mat_coor[mod].y2 = main->mat_coor[mod].y2 * main->mat.zoom + main->mat.center_y + main->mat.trans_y;
    main->rat = *ft_color(&main->rat, &main->mat, x, y);
    ft_trace_line(mod, main->mat_coor, &main->rat, *main);
    ft_clean_rat(main);
}

void    ft_normal_h(t_main *main, int y, int x, int mod)
{
    main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
    main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
    x++;
    if (x >= main->mat.size_x)
        return ;
    main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
    main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
    ft_modif_affichage(main, x, y, mod);
}
void    ft_depth_modifier_h(t_main *main, int y, int x, int mod)
{
    main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    x++;
    if (x >= main->mat.size_x)
        return ;
    main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    ft_modif_affichage(main, x, y, mod);
}


void    ft_depth_modifier_h1(t_main *main, int y, int x, int mod)
{
    main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
    main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
    x++;
    if (x >= main->mat.size_x)
        return ;
    main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    ft_modif_affichage(main, x, y, mod);
}

void    ft_depth_modifier_h2(t_main *main, int y, int x, int mod)
{
    main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    x++;
    if (x >= main->mat.size_x)
        return ;
    main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
    main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
    ft_modif_affichage(main, x, y, mod);
}

void    ft_normal_v(t_main *main, int y, int x, int mod)
{
    main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
    main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
    y++;
    if (y >= main->mat.size_y)
        return ;
    main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
    main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
    ft_modif_affichage(main, x, y, mod);
}

void    ft_depth_modifier_v(t_main *main, int y, int x, int mod)
{
    main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    y++;
    if (y >= main->mat.size_y)
        return ;
    main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    ft_modif_affichage(main, x, y, mod);
}

void    ft_depth_modifier_v1(t_main *main, int y, int x, int mod)
{
    main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
    main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
    y++;
    if (y >= main->mat.size_y)
        return ;
    main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    ft_modif_affichage(main, x, y, mod);
}

void    ft_depth_modifier_v2(t_main *main, int y, int x, int mod)
{
    main->mat_coor[mod].x1 = (x + (cos(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    main->mat_coor[mod].y1 = (y + (sin(main->mat.rad) * (main->mat.mat[y][x] + main->mat.depth)));
    y++;
    if (y >= main->mat.size_y)
        return ;
    main->mat_coor[mod].x2 = (x + (cos(main->mat.rad) * main->mat.mat[y][x]));
    main->mat_coor[mod].y2 = (y + (sin(main->mat.rad) * main->mat.mat[y][x]));
    ft_modif_affichage(main, x, y, mod);
}