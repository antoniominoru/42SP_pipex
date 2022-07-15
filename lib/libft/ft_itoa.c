/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 23:21:11 by aminoru-          #+#    #+#             */
/*   Updated: 2022/04/27 23:04:50 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizeint(long int n)
{
	if (n < 0)
		return (1 + ft_sizeint(-n));
	if ((n / 10) == 0)
		return (1);
	else
		return (1 + ft_sizeint(n / 10));
}

void	ft_int_to_char(long int n, char *num, long int i)
{
	if (n < 0)
	{
		num[0] = '-';
		n *= -1;
	}
	if (n >= 10)
		ft_int_to_char((n / 10), num, (i -1));
	num[i] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char		*num_char;
	long int	len;

	len = ft_sizeint(n);
	num_char = malloc((len +1) * sizeof(char));
	if (!num_char)
		return (NULL);
	num_char[len--] = '\0';
	ft_int_to_char(n, num_char, len);
	return (num_char);
}
