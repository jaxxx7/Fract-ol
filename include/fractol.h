/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:36:15 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/20 12:56:44 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_data;

typedef struct	s_complex
{
	double re;
	double im;
}				t_complex;

#define WIDTH 1920
#define HEIGHT 1080
#define MAX_ITER 100
// fractol.c
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			close_window(void *param);
int			name_check(char *name);
int			main(int argc, char **argv);
// hooks.c
int			key_hook(int keycode, t_data *img);
int			mouse_hook(int button, int x, int y, void *param);
// handle_pixel.c
int			handle_pixel(int x, int y, char *name);
int			coloration(int i);
int			point_iteration(t_complex c, int number);
t_complex	point_transformation(int x, int y, int number);
// init.c
void		z_init(t_complex *z, t_complex *c, int number);
void		init_plan(double *re_min, double *re_max, double *im_min, double *im_max, int number);
// utils.c
int			ft_strcmp(char *s1, char *s2);
void		print_usage(void);
int			create_trgb(int t, int r, int g, int b);
double		f_absolute(double number);
#endif