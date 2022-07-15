/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:00:27 by aminoru-          #+#    #+#             */
/*   Updated: 2022/05/28 18:32:35 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_specifier(t_format *fmt, t_holder *h)
{
	if (h->specifier == 'c')
		ft_convert_c(fmt, h);
	else if (h->specifier == 's')
		ft_convert_s(fmt, h);
	else if (h->specifier == 'p')
		ft_convert_p(fmt, h);
	else if (h->specifier == 'd' || h->specifier == 'i')
		ft_convert_d_i(fmt, h);
	else if (h->specifier == 'u')
		ft_convert_ux(fmt, h, DECIMAL_BASE);
	else if (h->specifier == 'o')
		ft_convert_ux(fmt, h, OCTAL_BASE);
	else if (h->specifier == 'x')
		ft_convert_ux(fmt, h, HEXADECIMAL_L_BASE);
	else if (h->specifier == 'X')
		ft_convert_ux(fmt, h, HEXADECIMAL_U_BASE);
	else if (h->specifier == '%')
		ft_convert_pct(h);
}
