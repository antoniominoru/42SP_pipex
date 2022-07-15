/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:57:56 by aminoru-          #+#    #+#             */
/*   Updated: 2022/04/13 14:47:45 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	l_d;
	size_t	i;

	l_d = ft_strlen(dest);
	if (size <= l_d)
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] && l_d < size - 1)
	{
		dest[l_d] = src[i];
		l_d++;
		i++;
	}
	dest[l_d] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}
