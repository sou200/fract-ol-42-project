/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 00:13:24 by serhouni          #+#    #+#             */
/*   Updated: 2022/12/17 19:04:55 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	b_ship(t_ld a, t_ld b)
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
		zb = 2 * fabsl(zb) * fabsl(tmp) + b;
	}
	return (i);
}

void	render_b_ship(t_data *data)
{
	int	j;
	int	i;
	int	ship;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			ship = b_ship((data->hp + i - WIDTH / 2) / data->zoom,
					(data->vp + j - HEIGHT / 2) / data->zoom);
			my_mlx_pixel_put(data, i, j, get_color(ship, data->color_set));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
