/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:27:03 by kerama            #+#    #+#             */
/*   Updated: 2025/10/18 09:02:18 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
#include <stdlib.h>

typedef struct s_list
{
	char			*data;
	struct s_list	*next;
}	t_list;
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	ft_lstremove_front(t_list **head);
void	ft_lstadd_back(t_list **head, char *line);

#endif