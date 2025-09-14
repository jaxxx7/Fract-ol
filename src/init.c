/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:13:23 by mhachem           #+#    #+#             */
/*   Updated: 2025/09/14 16:49:50 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void z_init(t_complex *z, t_complex *c, double re, double im, int number)
{
	if (!z || !c)
		return;

	if (number == 1)
	{
		z->re = 0;
		z->im = 0;
		c->re = re;
		c->im = im;
	}
	else if (number == 2)
	{
		z->re = re;
		z->im = im;
		c->re = -0.7;
		c->im = 0.27015;
	}
	else if (number == 3)
	{
		z->re = 0;
		z->im = 0;
		c->re = re;
		c->im = im;
	}
}

void	init_plan(t_data *img, int number)
{
	if (number == 1)
	{
		img->re_min = -2.5;
		img->re_max = 1.0;
		img->im_min = -1.5;
		img->im_max = 1.5;
	}
	else if (number == 2)
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
