/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:59:27 by olachgue          #+#    #+#             */
/*   Updated: 2024/11/04 18:31:41 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*last_occurence;

	p = (char *)s;
	last_occurence = NULL;
	while (*p)
	{
		if (*p == (char )c)
			last_occurence = p;
		p++;
	}
	if ((char )c == '\0')
		return (p);
	return (last_occurence);
}
