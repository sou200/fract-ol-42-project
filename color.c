/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:56:53 by serhouni          #+#    #+#             */
/*   Updated: 2022/12/16 01:41:46 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color_set0(double i)
{
	int				color;
	unsigned char	rgb;

	color = 0;
	rgb = 255 - i / ITER * 255.0;
	color = rgb;
	color = (color << 8) | rgb;
	color = (color << 8) | rgb;
	return (color);
}

static int	color_set1(double i)
{
	int		color;
	double	ratio;

	color = 0;
	ratio = i / ITER;
	color = (unsigned char)(9 * (1 - ratio) * pow(ratio, 3) * 255);
	color = (color << 8) | (unsigned char)(15 * pow((1 - ratio), 2) * 255);
	color = (color << 8) | (unsigned char)(8.5 * pow((1 - ratio), 3) * ratio
			* 255);
	return (color);
}

static int	color_set2(double i)
{
	int		color;
	double	ratio;

	color = 0;
	ratio = i / ITER;
	color = (unsigned char)(10 * (1 - ratio) * pow(ratio, 2) * 255);
	color = (color << 8) | (unsigned char)(3 * pow((1 - ratio), 3) * pow(ratio,
				2) * 255);
	color = (color << 8) | (unsigned char)(2 * pow((1 - ratio), 3)
			* (ratio) * 255);
	return (color);
}

static int	color_set3(double i)
{
	int		color;
	double	ratio;

	color = 0;
	ratio = i / ITER;
	color = 255 - (unsigned char)(10 * (1 - ratio) * pow(ratio, 3.5) * 255);
	color = (color << 8) | 255 - (unsigned char)(3 * pow((1 - ratio), 3)
			* pow(ratio, 2) * 255);
	color = (color << 8) | 255 - (unsigned char)(2 * pow((1 - ratio), 3)
			* (ratio) * 255);
	return (color);
}

int	get_color(double i, int set)
{
	if (set == 0)
		return (color_set0(i));
	else if (set == 1)
		return (color_set1(i));
	else if (set == 2)
		return (color_set2(i));
	else
		return (color_set3(i));
}
