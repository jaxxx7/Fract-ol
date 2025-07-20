/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:35:58 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/20 13:08:57 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	point_transformation(int x, int y, int number)
{
	t_complex	c;
	double		re_min;
	double		re_max;
	double		im_min;
	double		im_max;

	init_plan(&re_min, &re_max, &im_min, &im_max, number);
	c.re = re_min + ((double)x * (re_max - re_min) / WIDTH);
	c.im = im_max - ((double)y * (im_max - im_min) / HEIGHT);
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

int	handle_pixel(int x, int y, char *name)
{
	t_complex	c;
	int			i;
	int			color;
	int			number;

	number = 1;
	if (ft_strcmp(name, "mandelbrot") == 0)
		number = 1;
	else if (ft_strcmp(name, "julia") == 0)
		number = 2;
	else if (ft_strcmp(name, "burning-ship") == 0)
		number = 3;
	c = point_transformation(x, y, number);
	i = point_iteration(c, number);
	color = coloration(i);
	return (color);
}
