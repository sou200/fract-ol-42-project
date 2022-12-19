/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:58:18 by serhouni          #+#    #+#             */
/*   Updated: 2022/12/11 23:51:48 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(char sp, va_list *argsp)
{
	if (sp == '%')
		return (ft_putchar('%'));
	else if (sp == 'i' || sp == 'd')
		return (ft_putnbr(va_arg(*argsp, int)));
	else if (sp == 's')
		return (ft_putstr(va_arg(*argsp, char *)));
	else if (sp == 'c')
		return (ft_putchar(va_arg(*argsp, int)));
	else if (sp == 'u')
		return (ft_putnbr_base(va_arg(*argsp, unsigned int), "0123456789"));
	else if (sp == 'x')
		return (ft_putnbr_base(va_arg(*argsp, unsigned int),
				"0123456789abcdef"));
	else if (sp == 'X')
		return (ft_putnbr_base(va_arg(*argsp, unsigned int),
				"0123456789ABCDEF"));
	else if (sp == 'p')
		return (ft_putstr("0x") + ft_putnbr_base(va_arg(*argsp, unsigned long),
				"0123456789abcdef"));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	res = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && is_valid_sp(*(format + 1)))
			res += print_arg(*(++format), &args);
		else if (*format != '%')
			res += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (res);
}
