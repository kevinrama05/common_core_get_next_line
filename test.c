/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:26:53 by kerama            #+#    #+#             */
/*   Updated: 2025/10/19 13:33:17 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>

int	ft_hasnewline(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*s1;
	size_t	i;

	len = ft_strlen(s);
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_concatenate(char *file_content, char *buffer)
{
	size_t	len_fc = ft_strlen(file_content);
	size_t	len_buf = ft_strlen(buffer);
	char	*new_file_content = malloc(len_fc + len_buf + 1);
	size_t	i, j;

	if (!new_file_content)
		return NULL;

	i = 0;
	if (file_content)
	{
		while (i < len_fc)
		{
			new_file_content[i] = file_content[i];
			i++;
		}
	}
	j = 0;
	while (j < len_buf)
		new_file_content[i++] = buffer[j++];
	new_file_content[i] = '\0';
	return new_file_content;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

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

char	*ft_read_file(int fd)
{
	static char	*lines;
	char		*temp;
	char		buffer[BUFFER_SIZE + 1];
	size_t		n;
	t_lines		lines_struct;

	while (!ft_hasnewline(lines))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
			return NULL;
		if (n == 0)
			break;
		buffer[n] = '\0';
		temp = ft_concatenate(lines, buffer);
		if (!temp)
		{
			free(lines);
			return NULL;
		}
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
	int fd = open("test.txt", O_RDONLY);
	while (1)
	{
		char *c = ft_read_file(fd);
		if (c == NULL)
			break;
		else
		{
			printf("%s", c);
			free(c);
		}
	}
	return (0);
}