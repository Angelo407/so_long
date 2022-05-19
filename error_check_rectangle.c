/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_rectangle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:10:59 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/19 12:05:01 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_check_rectangle(t_display_map *map)
{
	int			i;
	int			j;
	int			k;
	int			fd;
	char		*line;

	fd = open(map->map, O_RDONLY);
	i = 0;
	j = 0;
	j = read_map_axe_x(map) + 1;
	while (i < read_map_axe_y(map))
	{
		line = get_next_line(fd);
		k = ft_strlen(line);
		if (k != j)
		{
			ft_printf("Erreur\nLa map n'est pas rectangle !\n");
			free(line);
			exit(0);
		}
		i++;
		free(line);
	}
	return (0);
}
// if (i == read_map_axe_y(map) - 1)
// 	k = k + 1;