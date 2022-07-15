/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertions_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:05:18 by aminoru-          #+#    #+#             */
/*   Updated: 2022/06/02 16:44:06 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_prefix_ux(t_holder *h)
{
	char	*tmp;

	tmp = h->argument;
	if (ft_strchr(h->prefix, '#'))
	{
		if (h->specifier == 'x')
			h->argument = ft_strjoin(PREFIX_HEX_L, tmp);
		if (h->specifier == 'X')
			h->argument = ft_strjoin(PREFIX_HEX_U, tmp);
		if (h->specifier == 'o')
			h->argument = ft_strjoin(PREFIX_OCTAL, tmp);
		free(tmp);
	}
}

void	ft_add_prefix(t_holder *h, int sign)
{
	int	len;

	len = ft_strlen(h->argument);
	if (h->specifier == 'd' || h->specifier == 'i')
	{
		len += 1;
		if (ft_strchr(h->prefix, PLUS) && sign == 1)
			ft_fill_left_pad(&h->argument, PLUS, len);
		else if (ft_strchr(h->prefix, SPACE) && sign == 1)
			ft_fill_left_pad(&h->argument, SPACE, len);
		else if (sign == -1)
			ft_fill_left_pad(&h->argument, MINUS, len);
	}
	else if (h->specifier == 'x' || h->specifier == 'X' \
			|| h->specifier == 'o')
		ft_prefix_ux(h);
}

void	ft_fill_left_pad(char **src, char padding, int width)
{
	char	*tmp;
	size_t	len;
	size_t	padlen;

	len = ft_strlen(*src);
	if (!width || width < (int)len)
		width = len;
	tmp = malloc((width + 1) * sizeof(char));
	if (!tmp)
		return ;
	padlen = width - len;
	ft_memset(tmp, padding, padlen);
	tmp[padlen] = '\0';
	ft_strlcat(tmp, *src, width + 1);
	free(*src);
	*src = tmp;
}

void	ft_fill_right_pad(char **src, char padding, int width)
{
	char	*tmp;
	size_t	len;
	size_t	padlen;

	len = ft_strlen(*src);
	if (!width || width < (int)len)
		width = len;
	tmp = malloc((width + 1) * sizeof(char));
	if (!tmp)
		return ;
	padlen = width - len;
	ft_strlcpy(tmp, *src, len +1);
	ft_memset(&tmp[len], padding, padlen);
	tmp[width] = '\0';
	free(*src);
	*src = tmp;
}
