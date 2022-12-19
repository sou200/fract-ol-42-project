/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:28:46 by serhouni          #+#    #+#             */
/*   Updated: 2022/12/19 03:44:29 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int keycode, int x, int y, t_data *data)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	if (keycode == SCR_DOWN)
	{
		data->zoom *= ZOOM_C;
		data->hp *= ZOOM_C;
		data->vp *= ZOOM_C;
		data->hp += x * (ZOOM_C - 1);
		data->vp += y * (ZOOM_C - 1);
		render_set(data);
	}
	else if (keycode == SCR_UP)
	{
		data->zoom /= ZOOM_C;
		data->hp /= ZOOM_C;
		data->vp /= ZOOM_C;
		render_set(data);
	}
	return (0);
}

int	handle_mouse_move(int x, int y, t_data *data)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	data->julia_const_a = x;
	data->julia_const_b = y;
	render_set(data);
	return 0;
}

