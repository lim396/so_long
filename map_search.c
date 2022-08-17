#include "so_long.h"

void	move_up(char **map, t_check_item *data, t_stack *branch_pos)
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

void	move_down(char **map, t_check_item *data, t_stack *branch_pos)
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

void	move_left(char **map, t_check_item *data, t_stack *branch_pos)
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

void	move_right(char **map, t_check_item *data, t_stack *branch_pos)
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
