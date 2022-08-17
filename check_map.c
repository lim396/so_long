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
		if ((map[0][i] != '1') || (map[map_height - 1][i] != '1'))
			return (false);
		i++;
	}
	i = 0;
	while (i < map_height)
	{
		if ((map[i][0] != '1') || (map[i][map_width - 1] != '1'))
			return (false);
		i++;
	}
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
	int	exit;
	int	collectible;

	player = 0;
	exit = 0;
	collectible = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
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
	t_check_item	*data;
	int				all_collectibles;
	bool			ret_flag;

	data = (t_check_item *)malloc(sizeof(t_check_item));
	if (data == NULL)
		return (false);
	branch_pos = new_sentinel();
	if (branch_pos == NULL)
		stack_error_handle(data, branch_pos, map);
	all_collectibles = 0;
	get_start_status(map, data, &all_collectibles);
	save_branch_point(data, branch_pos, map);
	while (is_move(map, data) || branch_pos->next != NULL)
	{
		map_move(map, data, branch_pos);
		back_to_branch_point(map, data, branch_pos);
	}
	ret_flag = 0;
	if ((data->exit_flag == 1) && (all_collectibles == data->collectible))
		ret_flag = 1;
	free(data);
	free(branch_pos);
	return (ret_flag);
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
		}
		return (true);
	}
	return (false);
}
