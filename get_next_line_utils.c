/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:34:13 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/10 00:15:44 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(char *str, char c)
{
	size_t	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (&str[i]);
	return (NULL);
}

char	*gnl_strdup(char *s)
{
	char	*new;
	char	*res;
	ssize_t	i;

	i = 0;
	while ((s[i] != '\0'))
		i++;
	res = malloc(i + 1);
	new = res;
	while (*s)
		*new++ = *s++;
	*new = 0;
	return (res);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	char	*res;

	new = malloc(len + 1);
	res = new;
	while (start--)
		s++;
	while (len-- && *s)
		*new++ = *s++;
	*new = 0;
	return (res);
}
