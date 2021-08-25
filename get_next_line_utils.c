#include "get_next_line.h"
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

size_t	ft_strlen(const char *str)
{
	return (*str ? ft_strlen(++str) + 1 : 0);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstring;
	size_t	i;
	size_t	j;

	if (s1 == 0)
		return ((char *)s2);
	if (s2 == 0)
		return ((char *)s1);
	nstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (nstring == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		nstring[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		nstring[i + j] = s2[j];
		j++;
	}
	nstring[i + j] = '\0';
	return (nstring);
}

char	*ft_strdup(const char *s1)
{
	char	*string;
	size_t	i;

	string = malloc(ft_strlen(s1) + 1);
	if (string == 0)
		return (0);
	else
	{
		i = 0;
		while (i < (ft_strlen (s1) + 1))
		{
			string[i] = s1[i];
			i++;
		}
	}
	return (string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		str = (char *)malloc(1 * sizeof(*s));
		str[count] = '\0';
		return (str);
	}
	str = (char *)malloc(len + 1 * sizeof(*s));
	if (!str)
		return (0);
	while (s[start] && count < len)
	{
		str[count] = s[start + count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
