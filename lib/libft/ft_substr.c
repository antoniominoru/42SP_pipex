/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:14:46 by aminoru-          #+#    #+#             */
/*   Updated: 2022/04/27 22:11:13 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen_s;

	if (!s)
		return (NULL);
	strlen_s = ft_strlen((char *)s);
	if (start > strlen_s)
		return (ft_strdup(""));
	if (strlen_s - start >= len)
		substr = malloc((len + 1) * sizeof(char));
	else
		substr = malloc((strlen_s - start + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, (s + start), (len + 1));
	return (substr);
}
