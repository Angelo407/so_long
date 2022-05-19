/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_axe_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:38:17 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/16 12:17:44 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map_axe_x(t_display_map *map)
{
	int		fd;
	int		len;
	char	*str;

	fd = open(map->map, O_RDONLY);
	str = get_next_line(fd);
	len = ft_strlen(str);
	free(str);
	return (len - 1);
}
