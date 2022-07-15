/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fs_sub_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:54:17 by aminoru-          #+#    #+#             */
/*   Updated: 2022/06/01 23:14:08 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fs_flags(t_format *fmt, t_holder *h)
{
	char	*tmp;

	if (!h->prefix)
		h->prefix = ft_strdup("");
	while (ft_strchr(P_HOLDER_ALL_FLAGS, fmt->format[fmt->i]))
	{
		if (fmt->format[fmt->i] == P_HOLDER_JUSTIFY)
			h->left_justify = 1;
		if (ft_strchr(P_HOLDER_PREFIX, fmt->format[fmt->i]))
		{
			tmp = h->prefix;
			h->prefix = ft_appendchr(tmp, fmt->format[fmt->i]);
			free(tmp);
		}
		if (fmt->format[fmt->i] == P_HOLDER_LEFT_PADS)
			h->padding = P_HOLDER_LEFT_PADS;
		fmt->i++;
	}
}

void	ft_fs_width(t_format *fmt, t_holder *h)
{
	int	width;

	width = h->width;
	if (fmt->format[fmt->i] == P_HOLDER_STAR)
	{
		width = va_arg(fmt->ap, int);
		if (width < 0)
		{
			h->left_justify = 1;
			width *= -1;
		}
		fmt->i++;
	}
	else if (ft_isdigit(fmt->format[fmt->i]))
	{
		width = 0;
		while (ft_isdigit(fmt->format[fmt->i]))
		{
			width = (width * 10) + (fmt->format[fmt->i] - '0');
			fmt->i++;
		}
	}
	h->width = width;
}

void	ft_fs_precision(t_format *fmt, t_holder *h)
{
	int	precision;

	precision = h->precision;
	if (fmt->format[fmt->i] == P_HOLDER_PRECISION)
	{
		fmt->i++;
		if (fmt->format[fmt->i] == P_HOLDER_STAR)
		{
			precision = va_arg(fmt->ap, int);
			fmt->i++;
		}
		else if (!ft_isdigit(fmt->format[fmt->i]))
			precision = 0;
		else
		{
			precision = 0;
			while (ft_isdigit(fmt->format[fmt->i]))
			{
				precision = (precision * 10) + (fmt->format[fmt->i] - '0');
				fmt->i++;
			}
		}
	}
	h->precision = precision;
}
