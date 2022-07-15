/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:07:12 by aminoru-          #+#    #+#             */
/*   Updated: 2022/06/01 20:22:39 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert_d_i_width(t_holder *h, int sign)
{
	if (h->left_justify)
	{
		ft_add_prefix(h, sign);
		ft_fill_right_pad(&h->argument, SPACE, h->width);
	}
	else
	{
		if (h->padding == SPACE)
		{
			ft_add_prefix(h, sign);
			ft_fill_left_pad(&h->argument, SPACE, h->width);
		}
		else if (h->padding == '0')
		{
			if (sign < 0)
				ft_fill_left_pad(&h->argument, h->padding, h->width - 1);
			else if (ft_strchr(h->prefix, SPACE))
				ft_fill_left_pad(&h->argument, h->padding, h->width - 1);
			else if (ft_strchr(h->prefix, PLUS))
				ft_fill_left_pad(&h->argument, h->padding, h->width - 1);
			else
				ft_fill_left_pad(&h->argument, h->padding, h->width);
			ft_add_prefix(h, sign);
		}
	}
}

void	ft_convert_d_i(t_format *fmt, t_holder *h)
{
	int			sign;
	long int	arg;

	sign = 1;
	arg = va_arg(fmt->ap, int);
	if (arg < 0)
		sign *= -1;
	h->argument = ft_uitoa(sign * arg, DECIMAL_BASE);
	if (h->precision > -1)
	{
		if (!h->precision && arg == 0)
		{
			free(h->argument);
			h->argument = ft_strdup("");
		}
		ft_fill_left_pad(&h->argument, '0', h->precision);
		h->padding = SPACE;
	}
	ft_convert_d_i_width(h, sign);
	h->len = ft_strlen(h->argument);
}
