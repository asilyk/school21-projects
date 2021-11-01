/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:06:19 by fabet             #+#    #+#             */
/*   Updated: 2021/11/01 12:32:19 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

static void	ft_cs_codes(const char format, va_list *ap, int *counter)
{
	char	*str;

	if (format == 'c')
	{
		ft_putchar_fd(va_arg(*ap, int), 1);
		(*counter)++;
	}
	if (format == 's')
	{
		str = va_arg(*ap, char *);
		ft_putstr_fd(str, 1);
		if (str != NULL)
		{
			*counter += ft_strlen(str);
		}
		else
		{
			*counter += 6;
		}
	}
}

static void	ft_dux_codes(const char format, va_list *ap, int *counter)
{
	if (format == 'd' || format == 'i')
	{
		*counter += ft_putnbr_fd(va_arg(*ap, int), 1);
	}
	if (format == 'u')
	{
		*counter += ft_putunbr(va_arg(*ap, unsigned int));
	}
	if (format == 'x' || format == 'X')
	{
		*counter += ft_puthexnbr(va_arg(*ap, int), format);
	}
}

static void	ft_parse_codes(const char *format, va_list *ap, int *counter)
{
	ft_cs_codes(*format, ap, counter);
	ft_dux_codes(*format, ap, counter);
	if (*format == 'p')
		*counter += ft_putptr((uintptr_t) va_arg(*ap, void *));
	if (*format == '%')
	{
		ft_putchar_fd('%', 1);
		(*counter)++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		counter;

	counter = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			counter++;
		}
		if (*format == '%')
		{
			format++;
			ft_parse_codes(format, &ap, &counter);
		}
		format++;
	}
	va_end(ap);
	return (counter);
}
