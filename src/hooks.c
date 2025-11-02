/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:46:21 by mhachem           #+#    #+#             */
/*   Updated: 2025/11/02 13:25:18 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_data *img)
{
	if (keycode == 65307)
		ft_cleanup(img);
	return (0);
}

static void	zoom_in(t_data *img, double mouse_re, double mouse_im)
{
	img->re_min = mouse_re - (mouse_re - img->re_min) / img->zoom_factor;
	img->re_max = mouse_re + (img->re_max - mouse_re) / img->zoom_factor;
	img->im_min = mouse_im - (mouse_im - img->im_min) / img->zoom_factor;
	img->im_max = mouse_im + (img->im_max - mouse_im) / img->zoom_factor;
}

static void	zoom_out(t_data *img, double mouse_re, double mouse_im)
{
	img->re_min = mouse_re - (mouse_re - img->re_min) * img->zoom_factor;
	img->re_max = mouse_re + (img->re_max - mouse_re) * img->zoom_factor;
	img->im_min = mouse_im - (mouse_im - img->im_min) * img->zoom_factor;
	img->im_max = mouse_im + (img->im_max - mouse_im) * img->zoom_factor;
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
		zoom_in(img, mouse_re, mouse_im);
	else if (button == 5)
		zoom_out(img, mouse_re, mouse_im);
	redraw(img);
	return (0);
}
