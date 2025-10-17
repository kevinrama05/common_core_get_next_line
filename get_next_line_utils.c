/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerama <kerama@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:26:53 by kerama            #+#    #+#             */
/*   Updated: 2025/10/17 13:21:30 by kerama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_is_newline(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == '\n')
			return (i++);
	}
	return (0);
}