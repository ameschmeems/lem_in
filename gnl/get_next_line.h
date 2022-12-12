/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 00:38:50 by kpucylo           #+#    #+#             */
/*   Updated: 2022/01/17 03:53:42 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin_gnl(char *s1, const char *s2);
char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(const char *s, unsigned int start, size_t len);
char	*ft_strdup_gnl(const char *s);
size_t	ft_strlen_gnl(const char *s);

#endif