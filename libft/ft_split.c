/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:34:32 by olachgue          #+#    #+#             */
/*   Updated: 2024/11/12 10:33:40 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*add_word(const char *s, char c, size_t *index)
{
	size_t	start;
	size_t	len;
	char	*word;
	size_t	i;

	len = 0;
	while (s[*index] == c)
		(*index)++;
	start = *index;
	while (s[*index] && s[*index] != c)
	{
		(*index)++;
		len++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_split(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	index;
	size_t	word_count;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	while (i < word_count)
	{
		split[i] = add_word(s, c, &index);
		if (!split[i])
		{
			free_split(split);
			return (NULL);
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}
