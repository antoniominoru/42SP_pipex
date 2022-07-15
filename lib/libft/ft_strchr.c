/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:13:39 by aminoru-          #+#    #+#             */
/*   Updated: 2022/06/02 16:44:56 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (unsigned char)c;
	if (!s)
		return (0);
	while (*s != '\0' && ch != *s)
		s++;
	if (ch == *s)
		return ((char *)s);
	return (0);
}
