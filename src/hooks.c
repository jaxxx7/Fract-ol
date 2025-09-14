/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:46:21 by mhachem           #+#    #+#             */
/*   Updated: 2025/09/14 16:57:57 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_data *img)
{
	mlx_hook(img->mlx_win, 17, 0, close_window, img);
	if (keycode == 65307)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*img;
	double	mouse_re;
	double	mouse_im;

	img = (t_data *)param;
	mouse_re = img->re_min + x * (img->re_max - img->re_min) / WIDTH;
	mouse_im = img->im_max - y * (img->im_max - img->im_min) / HEIGHT;
	if (button == 4)
	{
		img->re_min = mouse_re - (mouse_re - img->re_min) / img->zoom_factor;
		img->re_max = mouse_re + (img->re_max - mouse_re) / img->zoom_factor;
		img->im_min = mouse_im - (mouse_im - img->im_min) / img->zoom_factor;
		img->im_max = mouse_im + (img->im_max - mouse_im) / img->zoom_factor;
	}
	else if (button == 5)
	{
		img->re_min = mouse_re - (mouse_re - img->re_min) * img->zoom_factor;
		img->re_max = mouse_re + (img->re_max - mouse_re) * img->zoom_factor;
		img->im_min = mouse_im - (mouse_im - img->im_min) * img->zoom_factor;
		img->im_max = mouse_im + (img->im_max - mouse_im) * img->zoom_factor;
	}
	redraw(img);
	return (0);
}
