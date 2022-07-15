/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:48:44 by aminoru-          #+#    #+#             */
/*   Updated: 2022/06/01 20:23:35 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_placeholder(t_format *fmt)
{
	t_holder	*h;

	fmt->i++;
	h = ft_inicialize_placeholder();
	ft_format_specifiers(fmt, h);
	if (h->specifier)
	{
		ft_type_specifier(fmt, h);
		fmt->len += write(1, h->argument, h->len);
		free(h->argument);
	}
	free(h->prefix);
	free(h);
}
