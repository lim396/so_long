#include "so_long.h"

bool	is_move(char **map, t_check_item *data)
{
	return ((map[data->y][data->x + 1] != '1') || (map[data->y][data->x - 1] != '1') 
			|| (map[data->y + 1][data->x] != '1')
			|| (map[data->y - 1][data->x] != '1'));
}

void	get_start_status(char **map, t_check_item *data, int *all_collect)
{
	int	i;
	int	j;
	
	data->collectible = 0;
	data->exit_flag = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				data->x = j;
				data->y = i;
			}
			if (map[i][j] == 'C')
				(*all_collect)++;
			j++;
		}
		i++;
	}
}

int	measure_map_height(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
		i++;
	return (i);
}

bool	is_count_elem(char map_elem, int *p_count, int *e_count, int *c_count)
{
	if (map_elem == 'P')
		(*p_count)++;
	else if (map_elem == 'E')
		(*e_count)++;
	else if (map_elem == 'C')
		(*c_count)++;
	else if ((map_elem == '1') || (map_elem == '0'))
		;
	else
		return (false);
	return (true);	
}
