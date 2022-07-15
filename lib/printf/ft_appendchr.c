/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:59:18 by aminoru-          #+#    #+#             */
/*   Updated: 2022/06/01 20:22:07 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_appendchr(char const *s, char const ch)
{
	char	*concat_ch;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	concat_ch = malloc((len + 2) * sizeof(char));
	if (!concat_ch)
		return (NULL);
	i = 0;
	while (s[i])
	{
		concat_ch[i] = s[i];
		i++;
	}
	concat_ch[i++] = ch;
	concat_ch[i] = '\0';
	return (concat_ch);
}
