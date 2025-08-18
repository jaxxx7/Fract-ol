/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:30:28 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/31 13:32:52 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_loop(t_data img)
{
	img.y = 0;
	while (img.y < HEIGHT)
	{
		img.x = 0;
		while (img.x < WIDTH)
		{
			img.color = handle_pixel(img.x, img.y, img.name, &img);
			my_mlx_pixel_put(&img, img.x, img.y, img.color);
			img.x++;
		}
		img.y++;
	}
}