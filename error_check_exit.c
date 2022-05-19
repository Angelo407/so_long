/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:33:10 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/19 11:55:01 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_check_exit(t_display_map *map)
{
	int		fd;
	int		i;
	char	**str;

	fd = open(map->map, O_RDONLY);
	i = 0;
	str = malloc(sizeof(char *) * read_map_axe_y(map));
	while (i < read_map_axe_y(map))
	{
		str[i] = get_next_line(fd);
		if (ft_strchr(str[i], 'E') != NULL)
		{
			free_str(str, i + 1);
			return (0);
		}
		else
			i++;
	}
	ft_printf("Erreur\nIl manque une sortie !\n");
	free_str(str, read_map_axe_y(map));
	free(map->map);
	exit(0);
}

void	free_str(char **str, int line)
{
	t_errors	errors;
	int			i;

	i = 0;
	while (i < line)
	{
		if (str[i])
		{
			if (str[i])
				free(str[i]);
		}
		i++;
	}
	if (str)
		free(str);
	close (errors.fd);
}
