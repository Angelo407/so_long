/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:35:24 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/20 18:17:18 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	errors_all(t_display_map *map)
{
	int	error;
	char	*str;

	str = NULL;
	error = 0;
	error = error_check_rectangle(map);
	// if (error_check_invalid_letter(map) == 1)
	// {
	// 	ft_printf("Erreur\nIl y a min un char invalide ds la map !\n");
	// 	free_str(map->str, map->i + 1);
	// }
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
		while (1)
{
	sleep(1);
	printf("%d\n", getpid());
}
		exit (0);
	}
	return (0);
}
