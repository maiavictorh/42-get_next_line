/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:38:47 by victode-          #+#    #+#             */
/*   Updated: 2025/11/18 18:00:22 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *stack)
{
	size_t	i;
	char	*line;

	if (!stack)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	line = ft_substr(stack, 0, i + 1);
	return (line);
}

static char	*clean_stack(char *stack)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!stack)
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	if (stack[i] == '\0')
	{
		free(stack);
		return (NULL);
	}
	new = ft_substr(stack, i + 1, ft_strlen(stack));
	free(stack);
	return (new);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	*stack;
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
		{
			free(buff);
			free(stack);
			return (NULL);
		}
		else if (!bytes_read)
			return (NULL);
		buff[bytes_read] = '\0';
		stack = ft_strjoin(stack, buff);
		if (ft_strchr(stack, '\n'))
			break ;
	}
	free(buff);
	line = extract_line(stack);
	stack = clean_stack(stack);
	return (line);
}
