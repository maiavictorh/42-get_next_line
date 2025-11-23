/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:44:05 by victode-          #+#    #+#             */
/*   Updated: 2025/11/23 03:39:25 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_custom_strjoin(char *s1, char *s2)
{
	size_t	i;
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

char	*extract_line(char *stack)
{
	size_t	i;
	size_t	len;
	char	*line;

	if (!stack)
		return (NULL);
	i = 0;
	len = 0;
	while (stack[len] && stack[len] != '\n')
		len++;
	if (stack[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (free(stack), NULL);
	while (i < len)
	{
		line[i] = stack[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_stack(char *stack)
{
	size_t	i;
	size_t	len;
	char	*new;

	if (!stack)
		return (NULL);
	i = 0;
	len = 0;
	while (stack[len] && stack[len] != '\n')
		len++;
	if (stack[len] == '\n')
		len++;
	new = malloc(ft_strlen(stack) - len);
	if (!new)
		return (free(stack), NULL);
	while (len < ft_strlen(stack))
		new[i++] = stack[len++];
	new[i] = '\0';
	free(stack);
	return (new);
}
