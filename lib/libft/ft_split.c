/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:30:25 by aminoru-          #+#    #+#             */
/*   Updated: 2022/04/22 23:14:17 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cont_words(char const *s, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		if (*s == c)
			trigger = 0;
		s++;
	}
	return (i);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*next_w(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	words;
	size_t	word;

	if (!s)
		return (NULL);
	words = ft_cont_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	word = 0;
	while (word < words)
	{
		s = next_w(s, c);
		result[word] = ft_substr(s, 0, ft_wordlen(s, c));
		s += ft_wordlen(s, c);
		word++;
	}
	result[words] = NULL;
	return (result);
}
