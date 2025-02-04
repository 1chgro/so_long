/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:37:32 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/27 06:52:13 by olachgue         ###   ########.fr       */
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
	char	*p;

	p = (char *)s;
	while (*p != '\0')
	{
		if (*p == (char )c)
			return (p);
		p++;
	}
	if ((char )c == '\0')
		return (p);
	return (NULL);
}

char	*ft_stringjoin(char *s1, char *s2)
{
	char	*jnd;
	int		j;
	int		i;

	j = 0;
	i = -1;
	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc (1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	jnd = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!jnd)
		return (free(s1), NULL);
	while (s1[++i])
		jnd[i] = s1[i];
	while (s2[j])
		jnd[i++] = s2[j++];
	jnd[i] = '\0';
	free(s1);
	return (jnd);
}

char	*ft_strncpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
