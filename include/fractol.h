/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:36:15 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/13 16:28:32 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_data;

#define WIDTH 1920
#define HEIGHT 1080
#define MAX_ITER 100

void my_mlx_pixel_put(t_data *data, int x, int y, int color);
int close(void *param);
int key_hook(int keycode, t_data *img);
int mouse_hook(int button, int x, int y, void *param);
int handle_pixel(int x, int y);

#endif