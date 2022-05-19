/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:36:41 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/10 10:20:12 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_next_line(int fd)
{
	char	buffer;
	char	*str_line;
	int		i;

	if (fd < 0)
		return (NULL);
	i = 0;
	str_line = ft_strdup("");
	while (read(fd, &buffer, 1) > 0)
	{
		str_line = ft_strjoin(str_line, buffer);
		if (buffer == '\n')
			break ;
	}
	i = ft_strlen(str_line);
	if (i == 0)
	{
		free(str_line);
		str_line = NULL;
	}
	return (str_line);
}
