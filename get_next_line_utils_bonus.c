/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:44:05 by victode-          #+#    #+#             */
/*   Updated: 2025/12/03 18:29:05 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_nl(const char *s)
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

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_custom_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	s1_len = ft_strlen_nl(s1);
	s2_len = ft_strlen_nl(s2);
	join = malloc(s1_len + s2_len + 1);
	if (!join)
		return (free(s1), NULL);
	i = -1;
	while (++i < s1_len)
		join[i] = s1[i];
	j = -1;
	while (++j < s2_len)
		join[i + j] = s2[j];
	join[i + j] = '\0';
	return (free(s1), join);
}

void	clean_buffer(char *buffer)
{
	size_t	start;
	size_t	i;

	i = 0;
	start = ft_strlen_nl(buffer);
	while (start + i < BUFFER_SIZE)
	{
		buffer[i] = buffer[start + i];
		i++;
	}
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
}
