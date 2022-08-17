#include "so_long.h"

void	draw_to_window(void *img, t_data *sys_info, int y, int x)
{
	int	real_x;
	int	real_y;

	real_x = x * IMG_SIZE;
	real_y = y * IMG_SIZE;
	mlx_put_image_to_window
		(sys_info->graphic.mlx, sys_info->graphic.win, img, real_x, real_y);
}

void	draw_and_now_pos(t_data *sys_info, int y, int x)
{
	void	*img;

	img = sys_info->graphic.player_img;
	if (sys_info->exit_y == y && sys_info->exit_x == x)
		img = sys_info->graphic.overlap_img;
	draw_to_window(img, sys_info, y, x);
	sys_info->p_status.x = x;
	sys_info->p_status.y = y;
}

int	draw_map(t_data *sys_info)
{
	int	i;
	int	j;

	i = 0;
	while (sys_info->map[i])
	{
		j = 0;
		while (sys_info->map[i][j])
		{
			if (sys_info->map[i][j] == 'P')
				draw_and_now_pos(sys_info, i, j);
			if (sys_info->map[i][j] == 'E')
				draw_to_window(sys_info->graphic.exit_img, sys_info, i, j);
			if (sys_info->map[i][j] == 'C')
				draw_to_window(sys_info->graphic.collect_img, sys_info, i, j);
			if (sys_info->map[i][j] == '1')
				draw_to_window(sys_info->graphic.wall_img, sys_info, i, j);
			if (sys_info->map[i][j] == '0')
				draw_to_window(sys_info->graphic.road_img, sys_info, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
