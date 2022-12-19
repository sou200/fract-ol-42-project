/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:34:16 by serhouni          #+#    #+#             */
/*   Updated: 2022/12/19 03:44:08 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	julia(t_data *data, t_ld a, t_ld b)
{
	int		i;
	t_ld	za;
	t_ld	zb;
	t_ld	tmp;

	za = data->julia_const_a / WIDTH;
	zb = data->julia_const_b / HEIGHT;
	i = -1;
	while (++i < ITER && get_magnitude(a, b) <= 2.0)
	{
		tmp = a;
		a = tmp * tmp - b * b + za;
		b = 2 * tmp * b + zb;
	}
	return (i);
}

void	render_julia(t_data *data)
{
	int	j;
	int	i;
	int	jul;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			jul = julia(data, (data->hp + i - WIDTH / 2) / data->zoom, (data->vp
						+ j - HEIGHT / 2) / data->zoom);
			my_mlx_pixel_put(data, i, j, get_color(jul, data->color_set));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
