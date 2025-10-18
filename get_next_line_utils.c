/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:26:53 by kerama            #+#    #+#             */
/*   Updated: 2025/10/18 09:08:37 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <string.h>

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	size_t				i;
// 	unsigned char		*d;
// 	const unsigned char	*s;

// 	if (!dest && !src)
// 		return (NULL);
// 	i = 0;
// 	d = (unsigned char *)dest;
// 	s = (const unsigned char *)src;
// 	while (i < n)
// 	{
// 		d[i] = s[i];
// 		i++;
// 	}
// 	return (dest);
// }

// void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
// {
// 	void	*new_ptr;
// 	size_t	copy_size;

// 	if (new_size == 0)
// 	{
// 		free(ptr);
// 		return (NULL);
// 	}
// 	new_ptr = malloc(new_size);
// 	if (!new_ptr)
// 		return (NULL);
// 	if (ptr)
// 	{
// 		if (old_size < new_size)
// 			copy_size = old_size;
// 		else
// 			copy_size = new_size;
// 		ft_memcpy(new_ptr, ptr, copy_size);
// 		free(ptr);
// 	}
// 	return (new_ptr);
// }

void	ft_lstremove_front(t_list **head)
{
	t_list	*temp;

	if (head == NULL || *head == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

void	ft_lstadd_back(t_list **head, char *line)
{
	t_list	*new_node;
	t_list	*temp;

	if (!head)
		return ;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->data = line;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

char	*ft_read_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*file_content;
	size_t	n;

	while (1)
	{
		n = read(fd, buffer, sizeof(buffer) - 1);
		if (n <= 0)
			return (NULL);
		buffer[n] = '\0';
		file_content = ft_concatenate(file_content, buffer);
	}
	return (file_content);
}


