/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:37:54 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/01 22:35:29 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*split_line(char **statch, char **line)
{
	size_t	i;
	char	*new_statch;

	i = 0;
	new_statch = NULL;
	while (((*statch)[i] != '\n') && ((*statch)[i] != '\0'))
		i++;
	if ((*statch)[i] == '\n')
	{
		i++;
		*line = ft_substr(*statch, 0, i);
		new_statch = ft_strdup(*statch + i);
	}
	else
		*line = ft_strdup(*statch);
	free(*statch);
	*statch = NULL;
	return (new_statch);
}

ssize_t	make_line(int fd, char **buffer, char **statch, char **line)
{
	char	*tmp;
	ssize_t	n;
	int		flag;

	n = 1;
	flag = 1;
	while (flag && n)
	{
		n = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[n] = '\0';
		if (ft_strchr(*buffer, '\n'))
			flag = 0;
		tmp = *statch;
		*statch = ft_strjoin(tmp, *buffer);
		free(tmp);
	}
	free(*buffer);
	*buffer = NULL;
	*statch = split_line(statch, line);
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
	return (n);
}

char	*get_next_line(int fd)
{
	static char	*statch[10];
	char		*buffer;
	char		*line;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!statch[fd])
		statch[fd] = ft_strdup("");
	n = make_line(fd, &buffer, &statch[fd], &line);
	if (n && !line)
		return (NULL);
	return (line);
}
