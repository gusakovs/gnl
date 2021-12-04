/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgusakov <mgusakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:29:07 by mgusakov          #+#    #+#             */
/*   Updated: 2021/12/05 00:02:50 by mgusakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_to_ret(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = (char *)ft_calloc((i + 1), 1);
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i] = save[i];
	return (line);
}

char    *after_nl(char *save)
{
	char	*next_lines;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return(NULL);
	}
	next_lines = (char *)ft_calloc((ft_strlen(save) - i), 1);
	if (!next_lines)
		return (NULL);
	i++;
	while (save[i] != '\0')
		next_lines[j++] = save[i++];
	free(save);
	return (next_lines);
}

char    *ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	free (s1);
	return (str);
}

char    *eof(char *save, ssize_t ret, char *line)
{
	if (!save && !ret && !ft_strlen(line))
	{
		free (line);
		return (0);
	}
	else
		return (line);
}

char    *get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	ssize_t		ret;
	char		*line;

	buf = (char *)ft_calloc((BUFFER_SIZE + 1), 1);
	if (!buf)
		return (NULL);
	ret = 1;
	while (ret != 0 && !ft_strchr(save, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[ret] = '\0';
		save = ft_strjoin(save, buf);
	}
	free (buf);
	line = line_to_ret(save);
	save = after_nl(save);
	line = eof(save, ret, line);
	return (line);
}