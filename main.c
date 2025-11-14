/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 23:24:16 by victode-          #+#    #+#             */
/*   Updated: 2025/11/13 23:24:59 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*str;

	fd1 = open("test/test.txt", O_RDONLY);
	fd2 = open("test/longline.txt", O_RDONLY);
	str = get_next_line(fd1);
	printf("\n%s\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("\n%s\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("\n-%s-\n", str);
	free(str);
	str = get_next_line(fd1);
	printf("\n-%s-\n", str);
	free(str);
	close(fd1);
	close(fd2);
}
