/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:35:24 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/23 12:32:14 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	errors_all(t_display_map *map)
{
	int		error;
	char	*str;

	str = NULL;
	error = 0;
	error = error_check_rectangle(map);
	error += error_check_invalid_letter(map, str);
	error += error_wall_up_bottom(map);
	error += error_wall_left_right(map);
	error += error_check_exit(map);
	error += error_check_item(map);
	error += error_check_player(map);
	error += error_check_multiple_exits(map);
	error += error_check_multiple_players(map);
	if (error != 0)
	{
		free(map->map);
		close (map->fd);
		exit (0);
	}
	return (0);
}
