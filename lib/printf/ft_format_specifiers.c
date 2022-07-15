/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:42:14 by aminoru-          #+#    #+#             */
/*   Updated: 2022/06/01 23:13:25 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_format_specifiers(t_format *fmt, t_holder *h)
{
	ft_fs_flags(fmt, h);
	ft_fs_width(fmt, h);
	ft_fs_precision(fmt, h);
	ft_fs_specifier(fmt, h);
	if (!h->specifier && (ft_strchr(P_HOLDER_ALL, fmt->format[fmt->i])))
		ft_format_specifiers(fmt, h);
	return (h);
}

void	ft_fs_specifier(t_format *fmt, t_holder *h)
{
	if (!ft_strchr(P_HOLDER_ALL, fmt->format[fmt->i]))
	{
		if (ft_isprint(fmt->format[fmt->i]))
		{
			h->specifier = fmt->format[fmt->i];
			fmt->i++;
		}
	}
}
