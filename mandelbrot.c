/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:34:02 by serhouni          #+#    #+#             */
/*   Updated: 2022/12/17 19:43:36 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot(t_ld a, t_ld b)
{
	int		i;
	t_ld	za;
	t_ld	zb;
	t_ld	tmp;

	za = 0;
	zb = 0;
	i = -1;
	while (++i < ITER && get_magnitude(za, zb) <= 2.0)
	{
		tmp = za;
		za = za * za - zb * zb + a;
		zb = 2 * zb * tmp + b;
	}
	return (i);
}

void	render_mandelbrot(t_data *data)
{
	int	j;
	int	i;
	int	mandel;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			mandel = mandelbrot((data->hp + i - WIDTH / 2) / data->zoom,
					(data->vp + j - HEIGHT / 2) / data->zoom);
			my_mlx_pixel_put(data, i, j, get_color(mandel, data->color_set));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
