/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgusakov <mgusakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:35:55 by mgusakov          #+#    #+#             */
/*   Updated: 2021/12/05 00:09:39 by mgusakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

void    *ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = (char *)b;
	while (len > 0)
	{
		str[len - 1] = c;
		len--;
	}
	return (b);
}

void    ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

size_t  ft_strlen(const char *str)
{
	size_t	len;

	if(!str)
		return (0);

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char    *ft_strchr(const char *str, int c)
{
	unsigned int	i;

	if(!str)
		return (NULL);
	if (c == 0)
	{
		i = 0;
		while (str[i])
			i++;
		return ((char*)str + i);
	}
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}