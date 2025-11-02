/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:41:15 by mhachem           #+#    #+#             */
/*   Updated: 2025/11/02 13:42:41 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	point_transformation(int x, int y, t_data *img)
{
	t_complex	c;

	c.c_re = img->re_min + ((double)x * (img->re_max - img->re_min) / WIDTH);
	c.c_im = img->im_max - ((double)y * (img->im_max - img->im_min) / HEIGHT);
	c.z_re = 0;
	c.z_im = 0;
	return (c);
}

static void	apply_burning_ship(t_complex *l)
{
	l->z_re = f_absolute(l->z_re);
	l->z_im = f_absolute(l->z_im);
}

static int	calculate_iteration(t_complex *l, int i)
{
	double	tmp_re;
	double	tmp_im;

	tmp_re = l->z_re * l->z_re - l->z_im * l->z_im + l->c_re;
	tmp_im = 2 * l->z_re * l->z_im + l->c_im;
	l->z_re = tmp_re;
	l->z_im = tmp_im;
	if (l->z_re * l->z_re + l->z_im * l->z_im > 4)
		return (i);
	return (-1);
}

int	point_iteration(t_complex l, int number, double re, double im)
{
	int	i;
	int	result;

	i = 0;
	z_init(&l, re, im, number);
	while (i < MAX_ITER)
	{
		if (number == 3)
			apply_burning_ship(&l);
		result = calculate_iteration(&l, i);
		if (result != -1)
			return (result);
		i++;
	}
	return (MAX_ITER);
}

int	handle_pixel(int x, int y, int name, t_data *img)
{
	t_complex	c;
	int			i;

	img->zoom_factor = 1.2;
	c = point_transformation(x, y, img);
	i = point_iteration(c, name, c.c_re, c.c_im);
	img->color = coloration(i);
	return (img->color);
}
