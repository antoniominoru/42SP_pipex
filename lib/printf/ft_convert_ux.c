/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:23:57 by aminoru-          #+#    #+#             */
/*   Updated: 2022/06/01 20:23:01 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_ux(t_format *fmt, t_holder *h, char *base)
{
	unsigned int	nbr;
	char			*str_num;

	str_num = NULL;
	nbr = va_arg(fmt->ap, unsigned int);
	str_num = ft_uitoa(nbr, base);
	h->argument = ft_strdup(str_num);
	free(str_num);
	if (h->precision > -1)
	{
		if (!h->precision && nbr == 0)
		{
			free(h->argument);
			h->argument = ft_strdup("");
		}
		ft_fill_left_pad(&h->argument, '0', h->precision);
		h->padding = SPACE;
	}
	if (nbr)
		ft_add_prefix(h, 0);
	if (!h->left_justify)
		ft_fill_left_pad(&h->argument, h->padding, h->width);
	else
		ft_fill_right_pad(&h->argument, SPACE, h->width);
	h->len = ft_strlen(h->argument);
}
