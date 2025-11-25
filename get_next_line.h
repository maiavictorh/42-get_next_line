/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:55:52 by victode-          #+#    #+#             */
/*   Updated: 2025/11/25 17:08:55 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

/* ========== Main ========== */

char	*get_next_line(int fd);

/* ========== Utils ========== */

size_t	ft_strlen(const char *s);
int		ft_strchr(const char *s, char c);
char	*ft_custom_strjoin(char *s1, char *s2);
char	*extract_line(char *buffer);
char	*clean_buffer(char *buffer);

#endif