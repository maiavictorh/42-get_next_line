/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:38:47 by victode-          #+#    #+#             */
/*   Updated: 2025/11/23 03:34:52 by victode-         ###   ########.fr       */
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
			return (free(stack), stack = NULL, NULL);
		buff[bytes_read] = '\0';
		stack = ft_custom_strjoin(stack, buff);
		if (ft_strchr(stack, '\n'))
			break ;
	}
	if (!stack || stack[0] == '\0')
		return (free(stack), stack = NULL, NULL);
	line = extract_line(stack);
	stack = clean_stack(stack);
	return (line);
}
/* 
int	main(void)
{
	int		fd1;
	int		fd2;
	char	*s1;
	// char 	*s2;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("longline.txt", O_RDONLY);

	for (int i = 0; i < 5; i++)
	{
		s1 = get_next_line(fd1);
		printf("%s", s1);
		free(s1);
	}
	// printf("\nTest 2:\n");
	// s2 = get_next_line(fd2);
	// printf("%s", s2);
	// free(s2);

	printf("\n");
	close(fd1);
	close(fd2);
}
 */