/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:35:24 by aprosper          #+#    #+#             */
/*   Updated: 2022/05/18 13:41:51 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	errors_all(t_display_map *map)
{
	t_errors	errors;

	error_check_rectangle(map);
	error_wall_up_bottom(map);
	error_wall_left_right(map);
	error_check_exit(map);
	error_check_item(map);
	error_check_player(map);
	error_check_multiple_exits(map);
	error_check_multiple_players(map);
	return (0);
}
