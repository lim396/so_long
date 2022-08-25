/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:11:47 by shongou           #+#    #+#             */
/*   Updated: 2022/08/25 13:11:49 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(char **map, t_check_item *data, t_stack *branch_pos)
{
	check_item(map[data->y - 1][data->x], data);
	map[data->y][data->x] = '1';
	data->y -= 1;
	save_branch_point(data, branch_pos, map);
	if (!is_move(map, data) && branch_pos->next != NULL)
	{
		map[data->y][data->x] = '1';
		warp_branch_point(data, branch_pos);
	}
}

static void	move_down(char **map, t_check_item *data, t_stack *branch_pos)
{
	check_item(map[data->y + 1][data->x], data);
	map[data->y][data->x] = '1';
	data->y += 1;
	save_branch_point(data, branch_pos, map);
	if (!is_move(map, data) && branch_pos->next != NULL)
	{
		map[data->y][data->x] = '1';
		warp_branch_point(data, branch_pos);
	}
}

static void	move_left(char **map, t_check_item *data, t_stack *branch_pos)
{
	check_item(map[data->y][data->x - 1], data);
	map[data->y][data->x] = '1';
	data->x -= 1;
	save_branch_point(data, branch_pos, map);
	if (!is_move(map, data) && branch_pos->next != NULL)
	{
		map[data->y][data->x] = '1';
		warp_branch_point(data, branch_pos);
	}
}

static void	move_right(char **map, t_check_item *data, t_stack *branch_pos)
{
	check_item(map[data->y][data->x + 1], data);
	map[data->y][data->x] = '1';
	data->x += 1;
	save_branch_point(data, branch_pos, map);
	if (!is_move(map, data) && branch_pos->next != NULL)
	{
		map[data->y][data->x] = '1';
		warp_branch_point(data, branch_pos);
	}
}

void	map_move(char **map, t_check_item *data, t_stack *branch_pos)
{
	while (map[data->y - 1][data->x] != '1')
		move_up(map, data, branch_pos);
	while (map[data->y + 1][data->x] != '1')
		move_down(map, data, branch_pos);
	while (map[data->y][data->x - 1] != '1')
		move_left(map, data, branch_pos);
	while (map[data->y][data->x + 1] != '1')
		move_right(map, data, branch_pos);
}
