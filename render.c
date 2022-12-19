/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:43:19 by serhouni          #+#    #+#             */
/*   Updated: 2022/12/17 00:54:56 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render_set(t_data *data)
{
	if (data->image != NULL)
		mlx_destroy_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->image, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (data->set_id == 0)
		render_mandelbrot(data);
	else if (data->set_id == 1)
		render_julia(data);
	else if (data->set_id == 2)
		render_b_ship(data);
}
