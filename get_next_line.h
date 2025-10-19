/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:27:03 by kerama            #+#    #+#             */
/*   Updated: 2025/10/19 11:31:19 by kerama           ###   ########.fr       */
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
size_t	ft_strlen(const char *s);
char	*ft_concatenate(char *file_content, char *buffer);
char	*ft_read_file(int fd);

#endif
