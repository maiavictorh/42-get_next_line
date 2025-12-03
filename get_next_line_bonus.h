/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:55:52 by victode-          #+#    #+#             */
/*   Updated: 2025/12/02 18:51:41 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define FD_MAX 1024

/* ========== Main ========== */

char	*get_next_line(int fd);

/* ========== Utils ========== */

size_t	ft_strlen_nl(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_custom_strjoin(char *s1, char *s2);
void	clean_buffer(char *buffer);

#endif