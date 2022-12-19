/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:15:59 by serhouni          #+#    #+#             */
/*   Updated: 2022/11/18 20:14:53 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1), 1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (ft_putstr("(null)"), 6);
	while (s[i] != '\0')
		ft_putchar(s[i++]);
	return (i);
}

int	is_valid_sp(char c)
{
	char	*sps;
	int		i;

	i = -1;
	sps = "cspdiuxX%";
	while (sps[++i])
		if (sps[i] == c)
			return (1);
	return (0);
}
