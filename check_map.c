#include "so_long.h"

bool	is_surrounded_wall(char **map)
{
	int	i;
	int	map_width;
	int	map_height;

	map_width = ft_strlen(map[0]);
	map_height = measure_map_height(map);
	i = 0;
	while (i < map_width)
	{
//		printf("width %d\n", map_width);
		if ((map[0][i] != '1') || (map[map_height - 1][i] != '1'))
			return (false);
		i++;
	}
	i = 0;
	while (i < map_height)
	{
//		printf("height %d\n", map_height);
//		printf("invalid %c\n", map[i][0]);
//		printf("invalid %c\n", map[i][map_width - 1]);
		if ((map[i][0] != '1') || (map[i][map_width - 1] != '1'))
			return (false);
		i++;
	}
//	printf("true");
	return (true);

}

bool	is_rerectangle(char **map)
{
	int	i;
	int	j;
	int	map_width;
	int	map_height;

	map_width = ft_strlen(map[0]);
	map_height = measure_map_height(map);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != map_width)
			return (false);
		i++;
	}
	if (i != map_height)
		return (false);
	return (true);
}

bool	is_valid_map_elements(char **map)
{
	int	i;
	int	j;
	int	player;
	int exit;
	int	collectible;

	player = 0;
	exit = 0;
	collectible = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{ //cut func ?
			if (!(is_count_elem(map[i][j], &player, &exit, &collectible)))
				return (false);
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1 || collectible <= 0)
		return (false);
	return (true);
}

bool	is_complete_game(char	**map)
{
	t_stack			*branch_pos;
	t_check_item	*data; //not pointer is better?
	int				all_collectibles;
//	int				can_start_direction;

	data = (t_check_item *)malloc(sizeof(t_check_item));
	if (data == NULL)
		return (false);
	branch_pos = new_sentinel();
	if (branch_pos == NULL)
		stack_error_handle(data, branch_pos, map);
//		return (false);
	all_collectibles = 0;
	get_start_status(map, data, &all_collectibles);
//	can_start_direction = count_directions_can_go(map, data);
//	while (can_start_direction-- > 1)
//		push(branch_pos, data);
	save_branch_point(data, branch_pos, map);
	while (is_move(map, data) || branch_pos->next != NULL)
	{
		while (map[data->y - 1][data->x] != '1')
		{
			move_up(map, data, branch_pos);
//			printf("%c\n", map[data->y][data->x]);
//			printf("collect %d\n", data->collectible);
//			printf("x: %d\n", data->x);
//			printf("y: %d\n", data->y);
		}
		while (map[data->y + 1][data->x] != '1')
		{
			move_down(map, data, branch_pos);
//			printf("%c\n", map[data->y][data->x]);
//			printf("collect %d\n", data->collectible);
//			printf("x: %d\n", data->x);
//			printf("y: %d\n", data->y);
		}
		while (map[data->y][data->x - 1] != '1')
		{
			move_left(map, data, branch_pos);
//			printf("%c\n", map[data->y][data->x]);
//			printf("collect %d\n", data->collectible);
//			printf("x: %d\n", data->x);
//			printf("y: %d\n", data->y);
		}
		while (map[data->y][data->x + 1] != '1')
		{
			move_right(map, data, branch_pos);
//			printf("%c\n", map[data->y][data->x]);
//			printf("collect %d\n", data->collectible);
//			printf("x: %d\n", data->x);
//			printf("y: %d\n", data->y);
		}
		if (!is_move(map, data) && branch_pos->next != NULL)
		{
			map[data->y][data->x] = '1';
			warp_branch_point(data, branch_pos);
		}

	}
//	printf("collect %d\n", data->collectible);
//	printf("exit %d\n", data->exit_flag);
	if ((data->exit_flag == 1) && (all_collectibles == data->collectible))
	{
		free(data);
		free(branch_pos);
		return (1);
	}
	free(data);
	free(branch_pos);
	return (0);
}

bool	check_map(char **map)
{
	if (map && is_surrounded_wall(map)
		&& is_valid_map_elements(map) && is_rerectangle(map))
	{
		if (!is_complete_game(map))
		{
			ft_putstr_fd("\e[1;33m===Warning===\e[0m\n", 2);
			ft_putstr_fd("This map is impossible to success the game\n", 2);
			ft_putstr_fd("Quit game: Press esc or click X mark\n\n", 2);
//			printf("\e[1;33m===Warning===\e[0m\nThis map is impossible to success the game\nQuit game: Press esc or click X mark\n\n");
		}
		return (true);
	}
	return (false);
}
