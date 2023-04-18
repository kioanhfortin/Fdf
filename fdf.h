/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:02:57 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 17:38:36 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include "math.h"
# include "stdio.h"
# include "stdlib.h"

# define WINDOW_WIDTH 2000
# define WINDOW_HEIGHT 1180

typedef struct s_list
{
	void			*str;
	struct t_list	*next;
}					t_list;

typedef struct s_mat
{
	int				**mat;
	int				size_x;
	int				size_y;
	int				center_x;
	int				center_y;
	int				deg;
	double			rad;
	int				rot;
	double			rot_rad;
	int				zoom;
	int				depth;
	int				trans_x;
	int				trans_y;
	int				type_view;
}					t_mat;

typedef struct s_coor
{
	double			y1;
	double			y2;
	double			x1;
	double			x2;
	double			temp_x;
	double			temp_y;
	double			rot_x;
	double			rot_y;
}					t_coor;

typedef struct s_rat
{
	int				x;
	int				x1;
	int				x2;
	int				y;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
	int				e;
	int				e10;
	int				e01;
	int				ang;
	int				color;
	int				flag;
}					t_rat;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_main
{
	mlx_image_t		*img;
	mlx_t			*mlx;

	t_rat			rat;
	t_mat			mat;
	t_coor			*mat_coor;
}					t_main;

int					ft_isdigit(int c);
int					ft_isspace(char c);
t_list				*ft_lstnew(void *str);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_listclear(t_list *head);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst);
int					*ft_split(char *str, char *charset);
int					*ft_split_2(char **tab, int i, int *tab_int);
int					ft_check_hexa(char *tab);
int					ft_size_w(char *str, char *charset, int i);
int					ft_atoi_base(char *str, char *base);
long				ft_atol(char *str);
int					ft_str_is_alpha(char *str, int i);
int					ft_is_charset(char c, char *charset);
void				ft_free_tab(void **tab);
void				ft_free_tab2(void **tab);
void				ft_error_long(char *tab);
void				ft_error_int(int tab);
void				ft_write_error(void);
int					ft_strcmp(char *s1, char *s2);
int					ft_maplen(char *str);
t_list				*ft_mapwid(char *argv, t_mat *mat, t_list *map);
void				ft_clean_rat(t_main *main);
t_coor				*ft_init_coor(t_mat *mat);
void				ft_init_struct(t_mat *mat);
int					ft_tchek_rect(t_mat *mat, t_list *map);
void				ft_tchek_ext(char *argv);

double				ft_deg_rad(int deg);
void				ft_center(t_main *main);
void				ft_fill_coor_hori(t_main *main);
void				ft_fill_coor_hori_2(t_main *main, int mod, int x, int y);
void				ft_vue_hauteur_h(t_main *main, int y, int x, int mod);
void				ft_vue_hauteur_v(t_main *main, int y, int x, int mod);
void				ft_fill_coor_vert(t_main *main);
t_rat				*ft_color(t_rat *rat, t_mat *mat, int x, int y);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				ft_trace_line(int mod, t_coor *mat_coor, t_rat *rat,
						t_main main);
void				ft_declaration_rat(int mod, t_coor *mat_coor, t_rat *rat);
void				ft_check_frame(t_rat *rat, t_main main);
// t_rat				*ft_test(t_rat *rat, t_mat mat);

t_coor				*ft_rotate_coor(t_coor *mat_coor, t_mat *mat, int mod);
t_coor				*ft_rotate_coor_2(t_coor *mat_coor, int mod);
void				ft_modif_affichage(t_main *main, int x, int y, int mod);
void				ft_normal_h(t_main *main, int y, int x, int mod);
void				ft_depth_modifier_h(t_main *main, int y, int x, int mod);
void				ft_depth_modifier_h1(t_main *main, int y, int x, int mod);
void				ft_depth_modifier_h2(t_main *main, int y, int x, int mod);
void				ft_normal_v(t_main *main, int y, int x, int mod);
void				ft_depth_modifier_v(t_main *main, int y, int x, int mod);
void				ft_depth_modifier_v1(t_main *main, int y, int x, int mod);
void				ft_depth_modifier_v2(t_main *main, int y, int x, int mod);
void				ft_vue_isometrique_h(t_main *main, int y, int x, int mod);
void				ft_vue_iso_h(t_main *main, int y, int x, int mod);
void				ft_depth_iso_h(t_main *main, int y, int x, int mod);
void				ft_depth_iso_h1(t_main *main, int y, int x, int mod);
void				ft_depth_iso_h2(t_main *main, int y, int x, int mod);
void				ft_vue_isometrique_v(t_main *main, int y, int x, int mod);
void				ft_vue_iso_v(t_main *main, int y, int x, int mod);
void				ft_depth_iso_v(t_main *main, int y, int x, int mod);
void				ft_depth_iso_v1(t_main *main, int y, int x, int mod);
void				ft_depth_iso_v2(t_main *main, int y, int x, int mod);
void				ft_change_view_up(t_main *main);
void				ft_change_view_45(t_main *main);
void				ft_angle_plus(t_main *main);
void				ft_angle_minus(t_main *main);
void				ft_angle_re(t_main *main);

void				re_img(t_main *main);
void				x_plus_translation(t_main *main);
void				x_minus_translation(t_main *main);
void				x_re_translation(t_main *main);
void				y_plus_translation(t_main *main);
void				y_minus_translation(t_main *main);
void				y_re_translation(t_main *main);
void				depth_plus(t_main *main);
void				depth_minus(t_main *main);
void				depth_re(t_main *main);
void				ft_rot_plus(t_main *main);
void				ft_rot_minus(t_main *main);
void				ft_rot_re(t_main *main);
void				handle_keyboard(mlx_key_data_t keydata, void *param);
void				handle_keyboard_2(t_main *main);
void				zoom_in(t_main *main);
void				zoom_out(t_main *main);
void				handle_mouse(mouse_key_t button, action_t action,
						modifier_key_t mods, void *param);
void				*ft_exit(t_main *main);

#endif