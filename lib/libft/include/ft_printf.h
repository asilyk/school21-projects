/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:16:13 by fabet             #+#    #+#             */
/*   Updated: 2022/11/13 20:16:14 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putnbr(int n);
int	ft_putunnbr(unsigned int nbr);
int	ft_putunnbr_hex(unsigned long long nbr, char *base);
int	print_c(int arg);
int	print_s(char *arg);
int	print_decimal(int arg);
int	print_un_decimal(unsigned int arg);
int	print_pointer(unsigned long long arg);
int	print_un_hex(unsigned int arg, char type);
int	ft_printf(const char *string, ...);

#endif
