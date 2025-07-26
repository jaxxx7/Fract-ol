/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:35:58 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/26 17:50:13 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	point_transformation(int x, int y, t_data *img)
{
	t_complex	c;
	double		re_min;
	double		re_max;
	double		im_min;
	double		im_max;

	c.re = img->re_min + ((double)x * (img->re_max - img->re_min) / WIDTH);
	c.im = img->im_max - ((double)y * (img->im_max - img->im_min) / HEIGHT);
	return (c);
}

int	point_iteration(t_complex c, int number)
{
	int			i;
	t_complex	z;
	double		tmp_re;
	double		tmp_im;

	i = 0;
	z_init(&z, &c, number);
	while (i < MAX_ITER)
	{
		if (number == 3)
		{
			z.re = f_absolute(z.re);
			z.im = f_absolute(z.im);
		}
		tmp_re = z.re * z.re - z.im * z.im + c.re;
		tmp_im = 2 * z.re * z.im + c.im;
		z.re = tmp_re;
		z.im = tmp_im;
		if (z.re * z.re + z.im * z.im > 4)
			return (i);
		i++;
	}
	return (MAX_ITER);
}

int	coloration(int i)
{
	int	color_value;
	int	color;
	int	r;
	int	g;
	int	b;

	color_value = 255 * i / MAX_ITER;
	r = (color_value * 5) % 256;
	g = (color_value * 2) % 256;
	b = (color_value * 0) % 256;
	color = create_trgb(0, r, g, b);
	return (color);
}

int	handle_pixel(int x, int y, int name, t_data *img)
{
	t_complex	c;
	int			i;
	int			color;

	img->zoom_factor = 1.2;
	c = point_transformation(x, y, img);
	i = point_iteration(c, name);
	color = coloration(i);
	return (color);
}
