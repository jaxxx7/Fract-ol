/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:13:23 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/26 17:50:18 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	z_init(t_complex *z, t_complex *c, int number)
{
	if (number == 1 || number == 3)
	{
		z->re = 0;
		z->im = 0;
	}
	else if (number == 2)
	{
		z->re = c->re;
		z->im = c->im;
		c->re = -0.7;
		c->im = 0.27015;
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
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			// 1️⃣ Calculer la fractale pour ce pixel
			color = handle_pixel(x, y, img->name, img);

			// 2️⃣ Mettre le pixel dans l'image
			my_mlx_pixel_put(img, x, y, color);

			x++;
		}
		y++;
	}

	// 3️⃣ Afficher l'image mise à jour dans la fenêtre
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}
