/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:26:38 by kerama            #+#    #+#             */
/*   Updated: 2025/10/20 11:28:52 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

t_lines	ft_zeroed(t_lines lines)
{
	lines.line = NULL;
	lines.remainder = NULL;
	return lines;
}

t_lines ft_return_lines(char *s)
{
	t_lines	lines;
	size_t	i;
	size_t	start;
	size_t	len;

	if (!s)
		return (ft_zeroed(lines));
	len = ft_strlen(s);
	i = 0;
	start = 0;
	while (s[i] && s[i] != '\n')
	{
		i++;
		start++;
	}
	lines.line = ft_substr(s, 0, start + 1);
	lines.remainder = ft_substr(s, start + 1, len - (start + 1));
	return lines;
}

char	*invalid_n(char **lines, char **temp, ssize_t n)
{
	if (n < 0)
	{
		free(*lines);
		*lines = NULL;
		return (NULL);
	}
	if (n == 0)
	{
		if (*lines && **lines && !ft_hasnewline(*lines))
		{
			*temp = *lines;
			*lines = NULL;
			return (*temp);
		}
		free(*lines);
		*lines = NULL;
		return (NULL);
	}
	return (NULL);
}

char	*return_null(char **lines)
{
	free(*lines);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*lines;
	char		*temp;
	char		buffer[BUFFER_SIZE + 1];
	size_t		n;
	t_lines		lines_struct;

	while (!ft_hasnewline(lines))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			return (invalid_n(&lines, &temp, n));
		buffer[n] = '\0';
		temp = ft_concatenate(lines, buffer);
		if (!temp)
			return (return_null(&lines));
		if (lines)
			free(lines);
		lines = temp;
	}
	lines_struct = ft_return_lines(lines);
	temp = lines_struct.line;
	free(lines);
	lines = lines_struct.remainder;
	return temp;
}

int main(void)
{
	int fd = open("get_next_line.c", O_RDONLY);
	while (1)
	{
		char *c = get_next_line(fd);
		if (c == NULL)
			break;
		else
		{
			printf("--->  %s", c);
			free(c);
		}
	}
	return (0);
}