/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:41:15 by mhachem           #+#    #+#             */
/*   Updated: 2025/09/14 16:50:14 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Transforme un pixel (x, y) en un point complexe (c) */
t_complex	point_transformation(int x, int y, t_data *img)
{
	t_complex	c;

	c.re = img->re_min + ((double)x * (img->re_max - img->re_min) / WIDTH);
	c.im = img->im_max - ((double)y * (img->im_max - img->im_min) / HEIGHT);
	return (c);
}

/* Calcule le nombre d’itérations avant divergence */
int point_iteration(t_complex c, int number, double re, double im)
{
	int i;
	t_complex z;
	double tmp_re;
	double tmp_im;

	i = 0;
	z_init(&z, &c, re, im, number);

	while (i < MAX_ITER)
	{
		if (number == 3) // Burning Ship
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

/* Génère une couleur en fonction du nombre d’itérations */
int	coloration(int i)
{
	int	color_value;
	int	r;
	int	g;
	int	b;

	color_value = 255 * i / MAX_ITER;
	r = (color_value * 5) % 256;
	g = (color_value * 2) % 256;
	b = (color_value * 3) % 256; // corrigé pour ajouter du bleu
	return (create_trgb(0, r, g, b));
}

/* Gère un pixel : calcule la fractale et renvoie la couleur */
int	handle_pixel(int x, int y, int name, t_data *img)
{
	t_complex	c;
	int			i;

	img->zoom_factor = 1.2;
	c = point_transformation(x, y, img);
	i = point_iteration(c, name, c.re, c.im); // <-- passer c.re et c.im
	img->color = coloration(i);
	return (img->color);
}
