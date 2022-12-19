/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:57:42 by serhouni          #+#    #+#             */
/*   Updated: 2022/12/16 01:49:09 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	quit_pograme(t_data *data)
{
	mlx_destroy_image(data->mlx, data->image);
	exit(0);
	return (0);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == W_KEY || keycode == UP_KEY)
	{
		data->vp -= 50;
		render_set(data);
	}
	else if (keycode == S_KEY || keycode == DOWN_KEY)
	{
		data->vp += 50;
		render_set(data);
	}
	if (keycode == A_KEY || keycode == LEFT_KEY)
	{
		data->hp -= 50;
		render_set(data);
	}
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
	{
		data->hp += 50;
		render_set(data);
	}
	else if (keycode == SHIFT_KEY)
		shift_color(data);
	else if (keycode == ESC_KEY)
		quit_pograme(data);
	return (0);
}

void	shift_color(t_data *data)
{
	data->color_set = ++data->color_set % 4;
	render_set(data);
}
