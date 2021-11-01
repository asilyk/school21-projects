/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:17:12 by fabet             #+#    #+#             */
/*   Updated: 2021/10/30 17:57:32 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdint.h>

int	ft_printf(const char *format, ...);

int	ft_putptr(uintptr_t n);

int	ft_putunbr(unsigned int n);

int	ft_puthexnbr(unsigned int n, const char chcase);

#endif
