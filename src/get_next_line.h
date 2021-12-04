/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgusakov <mgusakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:29:41 by mgusakov          #+#    #+#             */
/*   Updated: 2021/12/05 00:09:23 by mgusakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdlib.h>

void    *ft_calloc(size_t count, size_t size);
void    *ft_memset(void *b, int c, size_t len);
void    ft_bzero(void *s, size_t n);
size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *str, int c);
char    *get_next_line(int fd);
char    *eof(char *save, ssize_t ret, char *line);
char    *ft_strjoin(char *s1, char *s2);
char    *after_nl(char *save);
char	*line_to_ret(char *save);


#endif