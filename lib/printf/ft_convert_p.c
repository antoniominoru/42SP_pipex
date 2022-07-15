/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:49:29 by aminoru-          #+#    #+#             */
/*   Updated: 2022/06/02 16:43:31 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_p(t_format *fmt, t_holder *h)
{
	void	*ptr;
	char	*number;

	number = NULL;
	ptr = va_arg(fmt->ap, void *);
	if (!ptr)
	{
		h->argument = ft_strdup("(nil)");
		free(number);
		h->len = 5;
		return ;
	}
	else
		number = ft_uitoa((unsigned long)ptr, HEXADECIMAL_L_BASE);
	h->argument = ft_strjoin(PREFIX_HEX_L, number);
	free(number);
	if (!h->left_justify)
		ft_fill_left_pad(&h->argument, SPACE, h->width);
	else
		ft_fill_right_pad(&h->argument, SPACE, h->width);
	h->len = ft_strlen(h->argument);
}
