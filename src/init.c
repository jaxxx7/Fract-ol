/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:13:23 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/20 13:09:32 by mhachem          ###   ########.fr       */
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

void	init_plan(double *re_min, double *re_max, double *im_min, double *im_max, int number)
{
	if (number == 1)
	{
		*re_min = -2.1;
		*re_max = 0.6;
		*im_min = -1.2;
		*im_max = 1.2;
	}
	else if (number == 2)
	{
		*re_min = -1.5;
		*re_max = 1.5;
		*im_min = -1.5;
		*im_max = 1.5;
	}
	else if (number == 3)
	{
		*re_min = -2.0;
		*re_max = 1.5;
		*im_min = -2.0;
		*im_max = 1.0;
	}
}
