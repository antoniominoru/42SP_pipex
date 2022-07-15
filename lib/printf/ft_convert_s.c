/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:27:14 by aminoru-          #+#    #+#             */
/*   Updated: 2022/06/01 20:22:56 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_s(t_format *fmt, t_holder *h)
{
	char	*s;
	char	*tmp;
	int		len;

	s = ft_strdup(va_arg(fmt->ap, char *));
	if (!s)
		s = ft_strdup("(null)");
	len = (int)ft_strlen(s);
	h->argument = malloc((len + 1) * sizeof(char));
	if (!h->argument)
		return ;
	ft_strlcpy(h->argument, s, len + 1);
	if (h->precision > -1)
	{
		tmp = h->argument;
		h->argument = ft_strndup(tmp, (size_t)h->precision);
		free(tmp);
	}
	if (!h->left_justify)
		ft_fill_left_pad(&h->argument, SPACE, h->width);
	else
		ft_fill_right_pad(&h->argument, SPACE, h->width);
	h->len = ft_strlen(h->argument);
	free(s);
}
