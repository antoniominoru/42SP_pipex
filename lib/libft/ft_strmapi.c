/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:32:55 by aminoru-          #+#    #+#             */
/*   Updated: 2022/04/25 21:42:39 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r_str;
	size_t	i;

	if (!s || !f)
		return (0);
	r_str = ft_strdup(s);
	if (!r_str)
		return (0);
	i = -1;
	while (r_str[++i])
		r_str[i] = f(i, r_str[i]);
	return (r_str);
}
