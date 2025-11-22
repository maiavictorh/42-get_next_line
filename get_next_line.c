/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:38:47 by victode-          #+#    #+#             */
/*   Updated: 2025/11/22 15:27:40 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	*stack;
	char		buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stack);
			stack = NULL;
			return (NULL);
		}
		buff[bytes_read] = '\0';
		stack = ft_strjoin(stack, buff);
		if (ft_strchr(stack, '\n'))
			break ;
	}
	if (!stack)
		return (NULL);
	if (stack[0] == '\0')
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	line = extract_line(stack);
	stack = clean_stack(stack);
	return (line);
}
