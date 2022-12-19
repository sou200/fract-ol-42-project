/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usual_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:18:31 by serhouni          #+#    #+#             */
/*   Updated: 2022/12/16 01:44:03 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57) || c == '-' || c == '+')
		return (1);
	return (0);
}

static void	preatoi(int *sign, const char *nptr, int *i)
{
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || nptr[*i] == ' ')
		(*i)++;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	ft_atoi(const char *nptr)
{
	long long	result;
	long long	presult;
	int			sign;
	int			i;

	i = 0;
	result = 0;
	sign = 1;
	preatoi(&sign, nptr, &i);
	while (ft_isdigit(nptr[i]))
	{
		presult = result;
		result = result * 10 + nptr[i] - '0';
		if ((result / 10) != presult)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		i++;
	}
	return (sign * result);
}

int	is_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}
