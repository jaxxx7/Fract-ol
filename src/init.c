/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:13:23 by mhachem           #+#    #+#             */
/*   Updated: 2025/11/02 13:42:09 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	z_init(t_complex *l, double re, double im, int number)
{
	if (!l)
		return ;
	l->z_re = 0;
	l->z_im = 0;
	l->c_re = re;
	l->c_im = im;
	if (number == 2)
	{
		l->z_re = re;
		l->z_im = im;
		l->c_re = -0.7;
		l->c_im = 0.27015;
	}
}

void	init_plan(t_data *img, int number)
{
	img->re_min = -2.5;
	img->re_max = 1.0;
	img->im_min = -1.5;
	img->im_max = 1.5;
	if (number == 2)
	{
		img->re_min = -2.0;
		img->re_max = 2.0;
		img->im_min = -2.0;
		img->im_max = 2.0;
	}
	else if (number == 3)
	{
		img->re_min = -2.2;
		img->re_max = 1.2;
		img->im_min = -2.5;
		img->im_max = 1.5;
	}
}

int	redraw(t_data *img)
{
	img->y = 0;
	while (img->y < HEIGHT)
	{
		img->x = 0;
		while (img->x < WIDTH)
		{
			img->color = handle_pixel(img->x, img->y, img->name, img);
			my_mlx_pixel_put(img, img->x, img->y, img->color);
			img->x++;
		}
		img->y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	init_mlx(t_data *img)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		return (0);
	img->mlx_win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "fractol");
	if (!img->mlx_win)
		return (0);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	if (!img->img)
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (1);
}

int	coloration(int i)
{
	int	color_value;
	int	r;
	int	g;
	int	b;

	color_value = 255 * i / MAX_ITER;
	r = (color_value * 5) % 256;
	g = (color_value * 2) % 256;
	b = (color_value * 3) % 256;
	return (create_trgb(0, r, g, b));
}
