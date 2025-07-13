/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:46:21 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/12 17:12:21 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_hook(int keycode, t_data *img)
{
	mlx_hook(img->mlx_win, 17, 0, close, img); // Destroy notify
	if (keycode == 65307) // ESC
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	return (0);
}

int mouse_hook(int button, int x, int y, void *param)
{
	t_data *img;

	img = (t_data *)param;
	if (button == 1) // Clic gauche
		printf("Left click at (%d, %d)\n", x, y);
	if (button == 2) // Clic droit
		printf("Right click at (%d, %d)\n", x, y);
	if (button == 3) // Molette clic
		printf("Middle click at (%d, %d)\n", x, y);
	if (button == 4) // Scroll up
		printf("Scroll up at (%d, %d)\n", x, y);
	if (button == 5) // Scroll down
		printf("Scroll down at (%d, %d)\n", x, y);

	return (0);
}
