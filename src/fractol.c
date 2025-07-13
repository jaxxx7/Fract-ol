/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:11:06 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/13 16:29:03 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close(void *param)
{
	t_data *img;
	
	img = (t_data *)param;
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit(0);
}


int main(void)
{
	t_data	img;
	int	x;
	int	y;
	int	color;

	y = 0;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "fractol");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	if (!img.mlx || !img.mlx_win)
		return (1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = handle_pixel(x, y);
			my_mlx_pixel_put(&img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_mouse_hook(img.mlx_win, mouse_hook, &img);
	mlx_loop(img.mlx);
}
