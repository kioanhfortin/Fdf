/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:47:54 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/13 15:28:46 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int ft_isspace(char c)
{
    if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f' || c == ' ')
        return (1);
    return (0);
}

int     ft_maplen(char *str)
{
    int i;
    int len;
    int flag;

    i = 0;
    len = 0;
    flag = 0;
    if (!str)
        return (-1);
    while (str[i])
    {
        if (!(ft_isdigit(str[i]) == 1 || ft_isspace(str[i]) == 1 || str[i] == '-' || str[i] == '+'))
            ft_write_error();
        if (ft_isdigit(str[i]) == 1 && (ft_isspace(str[i - 1]) == 1 || str[i - 1] == '-' || str[i - 1] == '+' || flag == 0))
        {
            len++;
            flag = 1;
        }
        i++;
    }
    return (len);
}

int     ft_tchek_rect(t_mat *mat, t_list *map)
{
    if (!map)
        return (0);
    while (map->next != NULL)
    {
        if (ft_maplen(map->str) != mat->size_x)
            return (0);
        map = (struct s_list*)map->next;
    }
    return (1);
}

t_list    *ft_mapwid(char *argv, t_mat *mat, t_list *map)
{
    int     i;
    int     fd;
    t_list    *node;
    char *str;
    
    i = 0;
    fd = open(argv, O_RDONLY);
    map = ft_lstnew(get_next_line(fd));
    node = map;
    str = map->str;
    if (map->str == NULL)
        ft_write_error();
    i++;
    mat->size_x = ft_maplen(map->str);
    while (str != NULL)
    {
        str = get_next_line(fd);
        if (ft_maplen(str) > mat->size_x)
            ft_write_error();
        ft_lstadd_back(&node, ft_lstnew(str));
        node = (struct s_list*)node->next;
        i++;
    }
    mat->size_y = i - 1;
    return (map);
}

void    ft_init_struct(t_mat *mat)
{
    mat->size_x = 0;
    mat->size_y = 0;
    mat->center_x = 0;
    mat->center_y = 0;
    mat->center_map_x = 0;
    mat->center_map_y = 0;
    mat->deg = 0;
    mat->rad = 0;
    mat->rot = 0;
    mat->rot_rad = 0;
    mat->zoom = 0;
    mat->depth = 0;
    mat->trans_x = 0;
}

void    ft_stock_mat(t_mat  *mat, t_list *map)
{
    int x;
    int y;
    int flag;
    t_list  *node;
    
    x = 0;
    y = 0;
    flag = 1;
    node = map;
    mat->mat = ft_calloc(mat->size_y + 1, sizeof(int*));
    if (!mat->mat)
        return ;
    while (y < mat->size_y)
    {
        if (node->str)
        {
            mat->mat[y] = ft_split(node->str, "\t\n\r\v\f ");
            node = (struct s_list*)node->next;
        }
        y++;   
    }
}

void    ft_print_mat(t_mat *mat)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (y < mat->size_y)
    {
        while (x < mat->size_x)
        {
            printf("%d ", mat->mat[y][x]);
            x++;
        }
        printf("\n");
        x = 0;
        y++;
    }
} 

char    *ft_copy_ext(char *argv, int i)
{
    char *s1;
    int     k;
    int     j;

    s1 = NULL;
    k = i;
    j = 0;
    while (argv[k++])
        j++;
    s1 = ft_calloc(j + 1, sizeof(char));
    if (!s1)
        return (NULL);
    k = i;
    j = 0;
    while (argv[k])
        s1[j++] = argv[k++];
    return (s1);
}

void     ft_tchek_ext(char *argv)
{
    int i;
    int j;
    char *s1;

    i = 0;
    j = 0;
    s1 = NULL;
    while (argv[i])
    {
        if (argv[i] == '.')
        { 
            s1 = ft_copy_ext(argv, i);
            if (ft_strcmp(s1, ".fdf") != 0)
                ft_write_error();
        }
        i++;
    }
    free (s1);
}

t_mat    ft_parsing(char **argv)
{
    t_list  *map;
    t_mat  mat;

    map = NULL;
    ft_init_struct(&mat);
    (void)argv;
    ft_tchek_ext(argv[1]);
    map = ft_mapwid(argv[1], &mat, map);
    printf("y = %d\n", mat.size_y);
    printf("x = %d\n", mat.size_x);
    ft_stock_mat(&mat, map);
    if (ft_tchek_rect(&mat, map) == 0)
        ft_write_error();
    ft_print_mat(&mat);
    ft_listclear(map);
    return(mat);
}

void    ft_clean_rat(t_main *main)
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

void    ft_center(t_main *main)
{
    main->mat.center_x = (WINDOW_WIDTH / 2) - (main->mat.size_x / 2 * main->mat.zoom);
    main->mat.center_y = (WINDOW_HEIGHT / 2) - (main->mat.size_y / 2 * main->mat.zoom);
}

t_rat *ft_color(t_rat *rat, t_mat *mat, int x, int y)
{
    if (rat->flag == 1)
    {
        if (mat->mat[y][x] > 0 && mat->mat[y][x - 1] > 0)
            rat->color = 1;
        else if (mat->mat[y][x] < 0 && mat->mat[y][x - 1] < 0)
            rat->color = -1;
        else if (mat->mat[y][x - 1] == 0 && mat->mat[y][x] == 0)
            rat->color = -2;
        else if ((mat->mat[y][x - 1] == 0 && mat->mat[y][x] < 0) || (mat->mat[y][x - 1] < 0 && mat->mat[y][x] == 0))
            rat->color = 2;
    }
    else
    {
        if (mat->mat[y - 1][x] > 0 && mat->mat[y][x] > 0)
                rat->color = 1;
        else if (mat->mat[y - 1][x] < 0 && mat->mat[y][x] < 0)
                rat->color = -1;
        else if (mat->mat[y - 1][x] == 0 && mat->mat[y][x] == 0)
                rat->color = -2;
        else if ((mat->mat[y - 1][x] == 0 && mat->mat[y][x] < 0) || (mat->mat[y - 1][x] < 0 && mat->mat[y][x] == 0))
            rat->color = 2;
    }
    return (rat);
}

t_coor  *ft_init_coor(t_mat *mat)
{
    t_coor  *mat_coor;
    
    mat_coor = ft_calloc(sizeof(t_coor), mat->size_x *mat->size_y);
    return (mat_coor);
}

double  ft_deg_rad(int deg)
{
    double rad;
    rad = deg * M_PI / 180.0;
    return (rad);
}

void    ft_fill_coor_hori(t_main *main)
{
    int x;
    int y;
    int mod;
    // t_coor  *mat_coor;

    x = 0;
    y = 0;
    mod = 0;
    main->rat.flag = 1;
    ft_center(main);
    main->mat.rad = ft_deg_rad(main->mat.deg);
    while (y < main->mat.size_y)
    {
        while (x < main->mat.size_x)
        {
            if(main->mat.mat[y][x] != 0 && main->mat.mat[y][x + 1] != 0)
                ft_depth_modifier_h(main, y, x, mod);
            else if (main->mat.mat[y][x] == 0 && main->mat.mat[y][x + 1] != 0)
                ft_depth_modifier_h1(main, y, x, mod);
            else if (main->mat.mat[y][x] != 0 && main->mat.mat[y][x + 1] == 0)
                ft_depth_modifier_h2(main, y, x, mod);
            else
                ft_normal_h(main, y, x, mod);
            mod++;
            x++;
        }
        mod++;
        x = 0;
        y++;
    }
    ft_print_mat(&main->mat);
}

void    ft_fill_coor_vert(t_main *main)
{
    int x;
    int y;
    int mod;

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
            if(main->mat.mat[y][x] != 0 && main->mat.mat[y + 1][x] != 0)
                ft_depth_modifier_v(main, y, x, mod);
            else if (main->mat.mat[y][x] == 0 && main->mat.mat[y + 1][x] != 0)
                ft_depth_modifier_v1(main, y, x, mod);
            else if (main->mat.mat[y][x] != 0 && main->mat.mat[y + 1][x] == 0)
                ft_depth_modifier_v2(main, y, x, mod);
            else
                ft_normal_v(main, y, x, mod);
            y++;
            ft_clean_rat(main);
            mod++;
        }
        mod++;
        y = 0;
        x++;
    }
}

// t_rat *ft_test(t_rat *rat, t_mat mat)
// {
//     (void)mat;
//     rat = ft_calloc(sizeof(int), 20);
//     rat->x1 = 100;
//     rat->y1 = 900;
//     rat->x2 = 900;
//     rat->y2 = 10;
//     return (rat);
// }

int main(int argc, char **argv)
{
    t_main  main;
    // t_mat   mat;
    // t_rat   *rat;

    // rat = NULL;
    if (argc == 2)
    {
        main.mat = ft_parsing(argv);
        main.mat_coor = ft_init_coor(&main.mat);
        main.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "KIOWINDOW", false);
        // main.mlx_win = mlx_new_window(main.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "KIOWINDOW");
        main.img = mlx_new_image(main.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
        // main.img.addr = mlx_get_data_addr(main.img.img, &main.img.bits_per_pixel, &main.img.line_length, &main.img.endian);

        main.mat.deg = 45;
        main.mat.zoom = 30;
        main.mat.rot = 0;
        // main.mat.depth = -1;
        // main.mat.trans_y = 0;
        // main.mat.trans_x = 0;

        ft_fill_coor_hori(&main);
        ft_fill_coor_vert(&main);
        mlx_image_to_window(main.mlx, main.img, 0, 0);
        mlx_key_hook(main.mlx, &handle_input, &main);
        mlx_loop(main.mlx);
        ft_free_tab2((void **)main.mat.mat);
    }
    else
        ft_write_error();
    return (0);
}