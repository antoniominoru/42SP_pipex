/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:34:05 by aminoru-          #+#    #+#             */
/*   Updated: 2022/04/27 22:29:48 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	s3 = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcpy(&s3[0], s1, len_s1 + 1);
	ft_strlcpy(&s3[len_s1], s2, len_s2 + 1);
	return (s3);
}
