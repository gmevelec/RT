/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:02:28 by crenault          #+#    #+#             */
/*   Updated: 2014/03/27 17:16:10 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <pthread.h>

/*
** t_bool defines
*/
# define FALSE			0
# define TRUE			1

/*
** objects defines
*/
# define NONE			0
# define SPHERE			1
# define PLANE			2
# define CYLINDRE		3
# define CONE			4
# define LIMITED_PLANE	5

/*
** t_bool
*/
typedef short	t_bool;

/*
** t_color
** r / 100
** g / 100
** b / 100
*/
typedef struct	s_color
{
	double		r;
	double		g;
	double		b;

}				t_color;

/*
** t_vec
*/
typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;

}				t_vec;

/*
** t_pix
*/
typedef struct	s_pix
{
	double		x;
	double		y;

}				t_pix;

/*
** t_pt
*/
typedef struct	s_pt
{
	double		x;
	double		y;
	double		z;

}				t_pt;

/*
** t_ang
*/
typedef struct	s_ang
{
	double		x;
	double		y;
	double		z;

}				t_ang;

/*
** t_ray
*/
typedef struct	s_ray
{
	t_vec		vector;
	t_pt		start_pt;

}				t_ray;

/*
** t_mat
** Coef / 100
*/
typedef struct	s_mat
{
	t_color		ambi;
	double		ambi_coef;

	t_color		diff;
	double		diff_coef;

	t_color		spec;
	double		spec_coef;

	double		shininess;

	double		index_refr;

	double		opacity_coef;
	double		reflect_coef;

}				t_mat;

/*
** t_iref
*/
typedef struct	s_iref
{
	double		n1;
	double		n2;

	t_ray		ray;
	t_pt		point;

}				t_iref;

/*
** t_cam
*/
typedef struct	s_cam
{
	t_pt		pos;
	t_ang		ang;

	double		rot_mat[3][3];

	double		focale;
	int			res_x;
	int			res_y;

	int			antialiasing;

	double		max_dist;
	int			max_depth;

	void		*img;
	char		*data_img;

}				t_cam;

/*
** t_env
*/
typedef struct	s_env
{
	void		*mlx;
	void		*win;

	int			bpp;
	int			sizeline;
	int			endian;

}				t_env;

/*
** t_obj3d
*/
typedef struct	s_obj3d
{
	t_pt		*pts;
	t_vec		*normals;
	t_pix		*tex;

}				t_obj3d;

/*
** t_lig
*/
typedef struct	s_lig
{
	t_color		color;
	double		coef_color;

	int			soft_shadows;
	double		interval_soft;

	t_pt		pos;
	t_ang		ang;

}				t_lig;

/*
** t_obj
*/
typedef struct	s_obj
{
	int			type;
	t_obj3d		obj3d;

	t_pt		pos;
	t_ang		ang;
	t_mat		mat;

	double		rot_mat[3][3];

	double		size;
	double		param1;

}				t_obj;

/*
** t_equ
*/
typedef struct	s_equ
{
	double		a;
	double		b;
	double		c;

}				t_equ;

/*
** t_threads
*/
typedef struct	s_threads
{
	pthread_t	thread;
	int			loading;

}				t_threads;

/*
** t_pack
*/
typedef struct	s_pack
{
	double		light_dist;

	t_pt		point;
	t_pt		light_pt;

	t_color		intensity;
	t_color		color;

	t_obj		obj;

	t_vec		normal;

}				t_pack;

/*
** t_gen
*/
typedef struct	s_gen
{
	t_env		e;
	t_bool		reload_screen;

	char		*filename;

	t_threads	*thrds;

	t_obj		*objs;
	int			nbr_objs;

	t_lig		*lights;
	int			nbr_lights;

	t_cam		cam;

}				t_gen;

/*
** RT.c
*/
t_gen			*g(void);
int				expose_hook(void);
int				key_relea(int keycode);

/*
** init.c
*/
void			init_data_addr(void);

/*
** errors.c
*/
void			error(char *str);

/*
** pixel_functions.c
*/
void			put_pixel(char *data, int y, int x, t_color color);
t_pt			create_pixel_pt(double x, double y);
t_color			get_pixel_color(double x, double y);

/*
** antia_functions.c
*/
t_color			antia_function(int y, int x, int antia);

/*
** core_system.c
*/
void			*render_picture(void *plus);
t_color			get_intensity(t_pt point, t_pt lig_pt, t_obj obj, t_pack pack);
t_color			get_perceived_color(t_pack pck, t_pt p, t_lig light, t_obj obj);
t_color			foreach_light(t_pt point, t_vec normal, t_obj obj);
t_color			ray_trace(t_ray ray, int depth, double last_obj);

/*
** vector_functions.c
*/
t_vec			create_vector(t_pt point1, t_pt point2);
t_vec			normalise_vector(t_vec vector);
double			dotproduct_vector(t_vec vector1, t_vec vector2);

/*
** color_funtions.c
*/
t_color			create_color(double red, double green, double blue);
t_color			add_color(t_color color1, t_color color2);
t_color			sub_color(t_color color1, t_color color2);
t_color			perc_color(t_color color, double perc);
t_color			cleaning_color(t_color color);

/*
** color_functions_1.c
*/
t_color			perc_rgb_color(t_color color, t_color perc);
t_color			light_color(t_color lig, t_color col, double ang, t_color inte);
t_color			shine_color(t_pack pck, t_color lig, double ang, t_mat mat);
t_color			sum_div_color(t_color color1, t_color color2, double div_);
t_color			moy_shine_color(t_color color1, t_color color2);

/*
** color_functions_2.c
*/
t_color			ref_colors(t_pack pack, double last_ir, t_ray ray, int depth);

/*
** ray_functions.c
*/
t_ray			create_ray(t_vec vector, t_pt start_pt);
t_ray			get_refl_ray(t_iref iref, t_vec normal);
t_ray			get_refr_ray(t_iref iref, t_vec normal);

/*
** object_functions.c
*/
t_vec			get_normal(t_obj obj, t_pt pos);
t_pt			get_intersection(t_ray ray, t_obj obj);
void			get_hit_obj(double *dist, t_pt *point, t_obj *obj, t_ray ray);

/*
** point_functions.c
*/
t_pt			create_point(double x, double y, double z);
double			get_dist_points(t_pt p1, t_pt p2);

/*
** objects_equations.c
*/
double			plane_equ(t_pt point, t_vec vector, t_obj plan);
double			sphere_equ(t_pt point, t_vec vector, t_obj sphere);
double			cyl_equ(t_pt point, t_vec vector, t_obj cyl);
double			cone_equ(t_pt point, t_vec vector, t_obj cone);

/*
** normal_functions.c
*/
t_vec			sphere_norm(t_obj obj, t_pt pos);
t_vec			plane_norm(t_obj obj, t_pt pos);
t_vec			cyl_norm(t_obj obj, t_pt pos);
t_vec			cone_norm(t_obj obj, t_pt pos);

/*
** soft_functions.c
*/
void			soft_shadows(void);

/*
** matrix_functions.c
*/
void			create_mat(double cx, double cy, double cz, double mat[3][3]);
t_vec			rotate_vector_mat(t_vec vector, double mat[3][3]);
t_pt			rotate_point_mat(t_pt origin, t_pt center, double mat[3][3]);

/*
** parser_functions.c
*/
void			ft_classic_parser(const char *file_name);
void			ft_get_objects(int fd, char *line);
void			ft_get_object_info(int fd, int i, char *line);

/*
** parser_functions_1.c
*/
void			ft_get_camera_resolution(char *line);
void			ft_get_camera_antialiasing(char *line);
void			ft_get_camera_max_depth(char *line);
void			ft_get_camera_max_distance(char *line);
void			ft_get_camera_position(char *line);

/*
** parser_functions_2.c
*/
void			ft_get_camera_rotation(char *line);
void			ft_get_camera(int fd);
void			ft_get_light_pos(char *line, int i);
void			ft_get_light_coef(char *line, int i);
void			ft_get_light_color(char *line, int i);

/*
** parser_functions_3.c
*/
void			ft_get_light_info(int fd, int i);
void			ft_get_lights(int fd, char *line);
void			ft_get_object_type(char *line, int i);
void			ft_get_object_position(char *line, int i);
void			ft_get_object_rotation(char *line, int i);

/*
** parser_functions_4.c
*/
void			ft_get_object_size(char *line, int i);
void			ft_get_object_ambi(char *line, int i);
void			ft_get_object_diff(char *line, int i);
void			ft_get_object_refl(char *line, int i);
void			ft_get_object_spec(char *line, int i);

/*
** parser_functions_5.c
*/
void			ft_get_object_color_info(char *line, int i);
void			ft_get_object_coef_ambi(char *line, int i);
void			ft_get_object_coef_diff(char *line, int i);
void			ft_get_object_coef_refl(char *line, int i);
void			ft_get_object_coef_spec(char *line, int i);

/*
** parser_functions_6.c
*/
void			ft_get_object_coef_info(char *line, int i);
void			ft_get_object_index_ref(char *line, int i);
void			ft_get_object_opacity_coef(char *line, int i);
void			ft_get_object_reflect_coef(char *line, int i);
void			ft_get_object_shininess(char *line, int i);

/*
** parser_functions_7.c
*/
void			ft_get_light_soft_shadows(char *line, int i);
void			ft_get_light_interval_soft(char *line, int i);
void			ft_get_light_rotation(char *line, int i);

/*
** mini_functions.c
*/
void			loading(double percent, int thread);
double			d_t_r(double degree);
void			time_display(unsigned long timestamp);

/*
** thread_functions.c
*/
void			launch_threads(void);

/*
** key_functions.c
*/
int				key_relea(int keycode);
int				key_press(int keycode);

/*
** iref_functions.c
*/
t_iref			create_iref(double n1, double n2, t_ray ray, t_pt point);

#endif
