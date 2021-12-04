/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgusakov <mgusakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:10:59 by mgusakov          #+#    #+#             */
/*   Updated: 2021/12/05 00:16:39 by mgusakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int fd;
	int i;

	fd = open("./test.txt", O_RDONLY);
	printf("fd : %d\n", fd);
	for (i = 1; i < 12; i++)
		printf("ligne %d : %s\n", i, get_next_line(fd));
	return (0);
}