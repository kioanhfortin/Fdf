/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:02:57 by kfortin           #+#    #+#             */
/*   Updated: 2023/03/23 16:21:13 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx/mlx.h"
# include "get_next_line.h"
# include "stdio.h"
# include "stdlib.h"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define GREEN_PIXEL 0x009FE2BF
# define RED_PIXEL 0x00C70039
# define LIGHT_GREEN_PIXEL 0x00DAF7A6

typedef struct s_list
{
    void    *str;
    struct  t_list *next;
}   t_list;

typedef struct s_mat
{
    int     **mat;
    int     size_x;
    int     size_y;
}   t_mat;

typedef struct s_rat
{
    int x;
    int x1;
    int x2;
    int y;
    int y1;
    int y2;
    int dx;
    int dy;
    int e;
    int e10;
    int e01;
} t_rat;

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

typedef struct s_main
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
} t_main;

// typedef struct s_rect
// {
// 	int	x;
// 	int	y;
// 	int width;
// 	int height;
// 	int color;
// }	t_rect;

int	    ft_isdigit(int c);
t_list	*ft_lstnew(void *str);
int	    ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void ft_listclear(t_list *head);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst);
// int     ft_lstsize(t_list *lst);
int	    *ft_split(char *str, char *charset);
long	ft_atol(char *str);
void	ft_free_tab(void **tab);
void	ft_free_tab2(void **tab);
void	ft_error_long(char **tab, int i, int *tab_int);
void	ft_write_error();
int     ft_strcmp(char *s1, char *s2);
t_list    *ft_mapwid(char *argv, t_mat *mat, t_list *map);

void    ft_fill_coor_struct(t_rat *rat, t_mat *mat);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void     ft_trace_seg(t_rat *rat, t_main main);
void    ft_trace_pixel(int x, int y, t_main main);

#endif