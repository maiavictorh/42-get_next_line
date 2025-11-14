/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:38:47 by victode-          #+#    #+#             */
/*   Updated: 2025/11/14 17:59:19 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *remain)
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

char	*get_next_line(int fd)
{
	char		*buff;
	int			bytes_read;
	static char	*remain;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(remain, '\n'))
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buff), NULL);
		buff[bytes_read] = '\0';
		remain = ft_strjoin(remain, buff);
	}
	line = extract_line(remain);
	return (line);
}
/*
int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *res = get_next_line(fd);
	printf("%s", res);
	free(res);
	close(fd);
}
*/