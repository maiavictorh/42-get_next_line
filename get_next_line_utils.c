/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:44:05 by victode-          #+#    #+#             */
/*   Updated: 2025/11/25 17:24:29 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

int	ft_strchr(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	if (*s == c)
		return (1);
	return (0);
}

char	*ft_custom_strjoin(char *s1, char *s2)
{
	int		i;
	size_t	j;
	char	*join;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (free(s1), NULL);
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s1);
	return (join);
}

char	*extract_line(char *buffer)
{
	size_t	i;
	size_t	len;
	char	*line;

	if (!buffer)
		return (NULL);
	i = 0;
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_buffer(char *buffer)
{
	size_t	i;
	size_t	len;
	char	*new;

	if (!buffer)
		return (NULL);
	i = 0;
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	if (len >= ft_strlen(buffer))
		return (free(buffer), NULL);
	new = malloc(ft_strlen(buffer) - len + 1);
	if (!new)
		return (free(buffer), NULL);
	while (buffer[len + i])
	{
		new[i] = buffer[len + i];
		i++;
	}
	new[i] = '\0';
	free(buffer);
	return (new);
}
