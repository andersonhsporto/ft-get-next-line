/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:25:24 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/08/30 14:51:50 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

char	*ft_strchr(char *str, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoinfree(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif