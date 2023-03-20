/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:20:03 by pboonpro          #+#    #+#             */
/*   Updated: 2023/02/26 15:20:03 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;

	if (*tofind == 0)
		return ((char *)str);
	if (len == 0)
		return (0);
	i = 0;
	while (str[i] != 0 && i < len)
	{
		j = 0;
		while (tofind[j] == str[i + j] && i + j < len
			&& str[i + j] && tofind[j])
		{
			j++;
			if (tofind[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*ptr;
	int		i;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (lens1 + lens2) + 1);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < lens1 + lens2)
	{
		if (i < lens1)
			ptr[i] = s1[i];
		else if (i >= lens1 && i < lens1 + lens2)
			ptr[i] = s2[i - lens1];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*ptr;

	if (!s)
		return (0);
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < len && start < ft_strlen(s))
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
