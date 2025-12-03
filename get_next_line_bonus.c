/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:38:47 by victode-          #+#    #+#             */
/*   Updated: 2025/12/03 16:08:56 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	line = NULL;
	while (!ft_strchr(line, '\n'))
	{
		if (buffer[fd][0] == '\0')
		{
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes_read == -1)
				return (free(line), NULL);
			if (bytes_read == 0)
				return (line);
		}
		line = ft_custom_strjoin(line, buffer[fd]);
		if (!line)
			return (free(line), NULL);
		clean_buffer(buffer[fd]);
	}
	return (line);
}
