/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:42:06 by serhouni          #+#    #+#             */
/*   Updated: 2022/12/19 03:39:31 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	intialize(t_data *data)
{
	data->zoom = (HEIGHT + WIDTH) / 8;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract-ol");
	data->image = NULL;
	data->addr = NULL;
	data->color_set = 0;
	data->vp = 0;
	data->hp = 0;
	data->julia_const_a = 0;
	data->julia_const_b = 0;
}

static void	set_hooks(t_data *data)
{
	mlx_key_hook(data->win, handle_key, data);
	mlx_mouse_hook(data->win, handle_mouse, data);
	mlx_hook(data->win, 6, 0, handle_mouse_move, data);
	mlx_hook(data->win, ON_DESTROY, 0, quit_pograme, data);
}

static int	handle_agruments(int argc, char const *argv[], t_data *data)
{
	if (argc == 2 && ft_strcmp(MANDELBROT_SET, argv[1]) == 0)
	{
		data->set_id = 0;
		return (1);
	}
	// else if (argc == 4 && ft_strcmp(JULIA_SET, argv[1]) == 0
	// 	&& is_number(argv[2]) && is_number(argv[3]))
	// {
	// 	data->set_id = 1;
	// 	data->julia_const_a = ft_atoi(argv[2]);
	// 	data->julia_const_b = ft_atoi(argv[3]);
	// 	return (1);
	// }
	else if (argc == 2 && ft_strcmp(JULIA_SET, argv[1]) == 0)
	{
		data->set_id = 1;
		return (1);
	}
	else if (argc == 2 && ft_strcmp(BURNING_SHIP_SET, argv[1]) == 0)
	{
		data->set_id = 2;
		return (1);
	}
	return (0);
}

static void	invalid_input(void)
{
	ft_printf("Usage :\n");
	ft_printf("\t$ ./Fractol <FRACTAL SET>\n");
	ft_printf("\t$ ./Fractol <FRACTAL SET> <x> <y> (for julia set)\n\n");
	ft_printf("availabe fractal sets :\n");
	ft_printf("\t* mandelbrot\n");
	ft_printf("\t* julia\n");
	ft_printf("\t* burning ship\n");
}

int	main(int argc, char const *argv[])
{
	t_data	data;

	if (handle_agruments(argc, argv, &data))
	{
		intialize(&data);
		render_set(&data);
		set_hooks(&data);
		mlx_loop(data.mlx);
	}
	else
		invalid_input();
	return (0);
}
