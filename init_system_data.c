/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_system_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:11:37 by shongou           #+#    #+#             */
/*   Updated: 2022/08/25 13:11:39 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_exit_pos(t_data *sys_info)
{
	int	i;
	int	j;

	i = 1;
	while (sys_info->map[i])
	{
		j = 1;
		while (sys_info->map[i][j])
		{
			if (sys_info->map[i][j] == 'E')
			{
				sys_info->exit_x = j;
				sys_info->exit_y = i;
			}
			j++;
		}
		i++;
	}
}

int	get_total_collect(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	init_graphic(t_data *sys_info, int win_width, int win_height)
{
	int	img_width;
	int	img_height;

	sys_info->graphic.win = mlx_new_window
		(sys_info->graphic.mlx, win_width, win_height, "so_long");
	sys_info->graphic.wall_img = mlx_xpm_file_to_image
		(sys_info->graphic.mlx, WALL_IMG, &img_width, &img_height);
	sys_info->graphic.road_img = mlx_xpm_file_to_image
		(sys_info->graphic.mlx, ROAD_IMG, &img_width, &img_height);
	sys_info->graphic.player_img = mlx_xpm_file_to_image
		(sys_info->graphic.mlx, PLAYER_IMG, &img_width, &img_height);
	sys_info->graphic.exit_img = mlx_xpm_file_to_image
		(sys_info->graphic.mlx, EXIT_IMG, &img_width, &img_height);
	sys_info->graphic.collect_img = mlx_xpm_file_to_image
		(sys_info->graphic.mlx, COLLECT_IMG, &img_width, &img_height);
	sys_info->graphic.overlap_img = mlx_xpm_file_to_image
		(sys_info->graphic.mlx, OVERLAP_IMG, &img_width, &img_height);
	if (!sys_info->graphic.win || !sys_info->graphic.wall_img
		|| !sys_info->graphic.road_img || !sys_info->graphic.player_img
		|| !sys_info->graphic.exit_img || !sys_info->graphic.collect_img
		|| !sys_info->graphic.overlap_img)
		mlx_error_handle(sys_info);
}

void	init_player_status(t_data *sys_info)
{
	sys_info->p_status.x = -1;
	sys_info->p_status.y = -1;
	sys_info->p_status.collected = 0;
	sys_info->p_status.moves_count = 0;
}

void	init_sys_info(t_data *sys_info)
{
	int	win_width;
	int	win_height;

	sys_info->graphic.win = NULL;
	sys_info->graphic.wall_img = NULL;
	sys_info->graphic.road_img = NULL;
	sys_info->graphic.player_img = NULL;
	sys_info->graphic.exit_img = NULL;
	sys_info->graphic.collect_img = NULL;
	sys_info->graphic.overlap_img = NULL;
	sys_info->graphic.mlx = mlx_init();
	if (sys_info->graphic.mlx == NULL)
		mlx_error_handle(sys_info);
	win_width = ft_strlen(sys_info->map[0]) * IMG_SIZE;
	win_height = measure_map_height(sys_info->map) * IMG_SIZE;
	init_graphic(sys_info, win_width, win_height);
	init_player_status(sys_info);
	get_exit_pos(sys_info);
	sys_info->finish_flag = 0;
	sys_info->all_collectibles = get_total_collect(sys_info->map);
}
