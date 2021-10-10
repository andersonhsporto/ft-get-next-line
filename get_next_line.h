/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:25:24 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/10/10 00:15:53 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

char	*gnl_strchr(char *str, char c);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoinfree(char *s1, char *s2);
char	*gnl_strdup(char *s);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
#endif