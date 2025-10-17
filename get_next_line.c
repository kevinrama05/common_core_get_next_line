/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:26:38 by kerama            #+#    #+#             */
/*   Updated: 2025/10/17 13:22:31 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char	get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer[BUFFER_SIZE + 1];
	char		*temp;
	size_t		n;

	if (fd < 0)
		return (NULL);
	if (remainder)
	{
		if ()
	}
}
