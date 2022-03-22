/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:06:19 by fabet             #+#    #+#             */
/*   Updated: 2021/11/06 07:37:34 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

static int	ft_is_set_char(const char ch, const char *set)
{
	while (*set)
	{
		if (*set == ch)
			return (1);
		set++;
	}
	return (0);
}

static void	ft_parse_codes(const char format, va_list *ap, int *counter)
{
	if (format == 'c')
		*counter += ft_putchar_fd(va_arg(*ap, int), 1);
	if (format == 's')
		*counter += ft_putstr_fd(va_arg(*ap, char *), 1);
	if (format == 'p')
		*counter += ft_putptr((uintptr_t) va_arg(*ap, void *));
	if (format == 'd' || format == 'i')
		*counter += ft_putnbr_fd(va_arg(*ap, int), 1);
	if (format == 'u')
		*counter += ft_putunbr(va_arg(*ap, unsigned int));
	if (format == 'x' || format == 'X')
		*counter += ft_puthexnbr(va_arg(*ap, int), format);
	if (format == '%')
		*counter += ft_putchar_fd('%', 1);
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
			counter += ft_putchar_fd(*format, 1);
		if (*format == '%')
		{
			format++;
			if (!ft_is_set_char(*format, "cspdiuxX%"))
				continue ;
			ft_parse_codes(*format, &ap, &counter);
		}
		format++;
	}
	va_end(ap);
	return (counter);
}
