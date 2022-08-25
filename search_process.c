/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:12:06 by shongou           #+#    #+#             */
/*   Updated: 2022/08/25 13:12:08 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_directions_can_go(char **map, t_check_item *data)
{
	int	count;

	count = 0;
	if (map[data->y - 1][data->x] != '1')
		count++;
	if (map[data->y + 1][data->x] != '1')
		count++;
	if (map[data->y][data->x - 1] != '1')
		count++;
	if (map[data->y][data->x + 1] != '1')
		count++;
	return (count);
}

int	save_branch_point(t_check_item *data, t_stack *branch_p, char **map)
{
	int		count;

	count = count_directions_can_go(map, data);
	while (count-- > 1)
	{
		if (push(branch_p, data) == -1)
			stack_error_handle(data, branch_p, map);
	}
	return (0);
}

void	check_item(char map, t_check_item *data)
{
	if (map == 'E')
		data->exit_flag = 1;
	if (map == 'C')
		data->collectible += 1;
}

void	warp_branch_point(t_check_item *data, t_stack *branch_pos)
{
	data->x = branch_pos->next->branch_x;
	data->y = branch_pos->next->branch_y;
	pop(branch_pos);
}
