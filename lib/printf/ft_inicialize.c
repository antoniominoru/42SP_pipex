/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inicialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:34:36 by aminoru-          #+#    #+#             */
/*   Updated: 2022/06/01 22:31:02 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_inicialize_stdout(const char *format, va_list ap)
{
	t_format	*fmt;

	fmt = malloc(sizeof(t_format));
	if (!fmt)
		return (NULL);
	fmt->format = format;
	va_copy(fmt->ap, ap);
	fmt->i = 0;
	fmt->len = 0;
	return (fmt);
}

t_holder	*ft_inicialize_placeholder(void)
{
	t_holder	*h;

	h = malloc(sizeof(t_holder));
	if (!h)
		return (NULL);
	h->left_justify = 0;
	h->width = 0;
	h->precision = -1;
	h->padding = ' ';
	h->specifier = '\0';
	h->argument = NULL;
	h->prefix = ft_strdup("");
	h->len = 0;
	return (h);
}
