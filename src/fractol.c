/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:11:06 by mhachem           #+#    #+#             */
/*   Updated: 2025/11/02 13:34:35 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_window(void *param)
{
	t_data	*img;

	img = (t_data *)param;
	ft_cleanup(img);
	return (0);
}

int	name_check(char *name)
{
	if (ft_strcmp("mandelbrot", name) == 0)
		return (1);
	else if (ft_strcmp("julia", name) == 0)
		return (1);
	else if (ft_strcmp("burning-ship", name) == 0)
		return (1);
	return (0);
}

int	get_fractal_number(char *name)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(name, "julia") == 0)
		return (2);
	else if (ft_strcmp(name, "burning-ship") == 0)
		return (3);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc != 2 || !name_check(argv[1]))
		return (print_usage(), 1);
	img.name = get_fractal_number(argv[1]);
	init_plan(&img, img.name);
	if (!init_mlx(&img))
		return (ft_putstr_fd("Error initializing MLX\n", 2), 1);
	ft_loop(&img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_mouse_hook(img.mlx_win, mouse_hook, &img);
	mlx_hook(img.mlx_win, 17, 0, close_window, &img);
	mlx_loop(img.mlx);
	ft_cleanup(&img);
	return (0);
}
