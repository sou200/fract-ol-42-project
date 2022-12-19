/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:33:03 by serhouni          #+#    #+#             */
/*   Updated: 2022/12/19 03:37:18 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "constants.h"
# include "ft_printf/ft_printf.h"
# include <math.h>
# include <stdlib.h>
# include <mlx.h>

typedef long double	t_ld;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*image;
	void			*addr;
	int				set_id;

	t_ld			zoom;
	t_ld			hp;
	t_ld			vp;

	int				bits_per_pixel;
	int				line_length;
	int				endian;

	t_ld			julia_const_a;
	t_ld			julia_const_b;

	int				color_set;
}					t_data;

double				get_magnitude(t_ld a, t_ld b);
int					handle_key(int keycode, t_data *param);
int					handle_mouse(int keycode, int x, int y, t_data *data);
int					handle_mouse_move(int x, int y, t_data *data);
void				render_mandelbrot(t_data *data);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				render_set(t_data *data);
void				render_julia(t_data *data);

int					quit_pograme(t_data *data);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *nptr);
int					is_number(const char *str);
void				render_b_ship(t_data *data);

int					get_color(double i, int set);
void				shift_color(t_data *data);

#endif
