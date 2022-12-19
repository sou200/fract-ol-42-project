/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:13:36 by serhouni          #+#    #+#             */
/*   Updated: 2022/11/18 19:10:11 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nb, char *base)
{
	unsigned int	baselen;

	baselen = ft_strlen(base);
	if (nb < baselen)
		return (ft_putchar(base[nb]));
	else
		return (ft_putnbr_base(nb / baselen, base) + ft_putnbr_base(nb
				% baselen, base));
}

int	ft_putnbr(long nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		return (1 + ft_putnbr(-nb));
	}
	else if (nb <= 9)
		return (ft_putchar('0' + nb));
	else
		return (ft_putnbr(nb / 10) + ft_putnbr(nb % 10));
}
