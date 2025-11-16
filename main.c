/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 23:24:16 by victode-          #+#    #+#             */
/*   Updated: 2025/11/16 19:47:07 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*s1;
	// char 	*s2;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("longline.txt", O_RDONLY);

	for (int i = 0; i < 1; i++)
	{
		s1 = get_next_line(fd1);
		printf("%s", s1);
		free(s1);
	}
	printf("\nTest 2:\n");
/* 	s2 = get_next_line(fd2);
	printf("%s", s2);
	free(s2);
	printf("\n");
 */
	close(fd1);
	close(fd2);
}