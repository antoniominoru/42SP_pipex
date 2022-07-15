/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 02:08:07 by aminoru-          #+#    #+#             */
/*   Updated: 2022/04/27 15:48:01 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ini;
	char		ch;

	ch = (unsigned char)c;
	ini = s;
	s = (s + ft_strlen(s));
	while (*s != *ini && ch != *s)
		s--;
	if (ch == *s)
		return ((char *)s);
	return (0);
}
