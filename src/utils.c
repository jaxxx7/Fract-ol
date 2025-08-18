/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:25:44 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/31 13:02:31 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	f_absolute(double number)
{
	if (number < 0)
		number = -number;
	return (number);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	print_usage(void)
{
	write(1, "Available fractals:\n", 20);
	write(1, "- mandelbrot\n", 13);
	write(1, "- julia\n", 8);
	write(1, "- burning-ship\n", 16);
	write(1, "Usage: ./fractol <fractal_name>\n", 32);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
