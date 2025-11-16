/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:38:47 by victode-          #+#    #+#             */
/*   Updated: 2025/11/16 20:07:20 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *remain)
{
	size_t	i;
	char	*line;

	if (!remain)
		return (NULL);
	i = 0;
	while (remain[i] && remain[i] != '\n')
		i++;
	line = ft_substr(remain, 0, i + 1);
	return (line);
}

static char	*clean_remain(char *remain)
{
	size_t	i;
	char	*new;

	i = 0;
	while (remain[i] && remain[i] != '\n')
		i++;
	if (remain[i] == '\0')
		return (NULL);
	new = ft_substr(remain, i + 1, ft_strlen(remain));
	return (new);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	*remain;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buff), NULL);
		buff[bytes_read] = '\0';
		remain = ft_strjoin(remain, buff);
		if (ft_strchr(remain, '\n'))
			break ;
	}
	line = extract_line(remain);
	remain = clean_remain(remain);
	return (line);
}
