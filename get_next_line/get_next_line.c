/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:37:38 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/27 06:52:09 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_from_file(int fd, char *leftover)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (free(leftover), leftover = NULL, NULL);
	while (bytes > 0 && (!leftover || !ft_strchr(leftover, '\n')))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(leftover), NULL);
		buffer[bytes] = '\0';
		leftover = ft_stringjoin(leftover, buffer);
		if (!leftover)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (leftover);
}

char	*get_till_newline(char *leftover)
{
	size_t	len;
	char	*line;

	len = 0;
	while (leftover[len] != '\n' && leftover[len] != '\0')
		len++;
	if (leftover[len] == '\n')
		len++;
	if (len == 0 && leftover[len] == '\0')
		return (NULL);
	line = (char *)malloc(len + 1 * sizeof(char));
	if (!line)
		return (NULL);
	ft_strncpy(line, leftover, len);
	return (line);
}

char	*update_leftover(char *leftover)
{
	char	*new_leftover;
	int		j;
	int		i;
	size_t	left_len;

	j = 0;
	i = 0;
	left_len = ft_strlen(leftover);
	while (leftover[j] != '\n' && leftover[j] != '\0')
		j++;
	if (!leftover[j])
		return (free(leftover), leftover = NULL, NULL);
	j++;
	new_leftover = (char *)malloc((left_len - j + 1) * sizeof(char));
	if (!new_leftover)
		return (free(leftover), leftover = NULL, NULL);
	while (leftover[j])
		new_leftover[i++] = leftover[j++];
	new_leftover[i] = '\0';
	free(leftover);
	return (new_leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover[OPEN_MAX];
	char		*line;
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	leftover[fd] = read_from_file(fd, leftover[fd]);
	if (!leftover[fd])
		return (NULL);
	line = get_till_newline(leftover[fd]);
	if (!line)
		return (free(leftover[fd]), leftover[fd] = NULL, NULL);
	tmp = update_leftover(leftover[fd]);
	leftover[fd] = tmp;
	return (line);
}
