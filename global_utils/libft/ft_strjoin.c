/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:04:21 by olachgue          #+#    #+#             */
/*   Updated: 2024/11/05 10:30:44 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*jnd_str;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	jnd_str = (char *)malloc(sizeof(char) * total_len);
	if (!jnd_str)
		return (NULL);
	ft_strlcpy(jnd_str, s1, total_len);
	ft_strlcat(jnd_str, s2, total_len);
	return (jnd_str);
}
