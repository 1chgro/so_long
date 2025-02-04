/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:14:06 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/27 06:52:02 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*read_from_file(int fd, char *left);
char	*get_till_newline(char *left);
char	*update_leftover(char *left);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_stringjoin(char *s1, char *s2);
char	*ft_strncpy(char *dst, char *src, size_t n);

#endif