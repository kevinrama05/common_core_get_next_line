/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:27:03 by kerama            #+#    #+#             */
/*   Updated: 2025/10/20 11:25:26 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
#include <stdlib.h>

typedef struct s_lines
{
	char	*line;
	char	*remainder;
}	t_lines;
int	ft_hasnewline(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_concatenate(char *file_content, char *buffer);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_lines	ft_zeroed(t_lines lines);
t_lines ft_return_lines(char *s);
char	*invalid_n(char **lines, char **temp, ssize_t n);
char	*return_null(char **lines);
char	*get_next_line(int fd);

#endif
