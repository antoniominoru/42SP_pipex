/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:34:34 by aminoru-          #+#    #+#             */
/*   Updated: 2022/06/01 22:21:16 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_c(t_format *fmt, t_holder *h)
{
	char	ch;

	ch = va_arg(fmt->ap, wint_t);
	if (!h->width)
		h->width += 1;
	h->argument = malloc(h->width * sizeof(char));
	if (!h->argument)
		return ;
	ft_memset(h->argument, SPACE, h->width);
	if (h->left_justify == 1)
		h->argument[0] = ch;
	else
		h->argument[h->width - 1] = ch;
	h->len = h->width;
}
