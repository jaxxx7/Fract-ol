/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:35:58 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/13 16:42:30 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t palette[MAX_ITER] = {0};

void init_palette()
{
	int	i;

	i = 0;
	while (i < MAX_ITER)
	{
		int blue = 128 + (127 * i) / MAX_ITER;
		palette[i] = (blue);
		i++;
	}
}

int handle_pixel(int x, int y)
{
	double re, im;
	double z_re, z_im;
	double c_re, c_im;
	int i;

	re = -2.0 + x * (4.0 / WIDTH);
	im = 1.5 - y * (3.0 / HEIGHT);
	c_re = re;
	c_im = im;
	z_re = 0.0;
	z_im = 0.0;
	for (i = 0; i < MAX_ITER; i++)
	{
		double z_re_tmp = z_re * z_re - z_im * z_im + c_re;
		double z_im_tmp = 2 * z_re * z_im + c_im;

		z_re = z_re_tmp;
		z_im = z_im_tmp;

		if ((z_re * z_re + z_im * z_im) > 4.0)
			break;
	}
	return i;
}

uint32_t	get_color(int iter_count)
{
	if (iter_count == MAX_ITER)
		return (0x00000000);
	else
		return (palette[iter_count]);
}
