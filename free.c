#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	destroy_mlx(t_data *sys_info)
{
	if (sys_info->graphic.wall_img != NULL)
		mlx_destroy_image(sys_info->graphic.mlx, sys_info->graphic.wall_img);
	if (sys_info->graphic.road_img != NULL)
		mlx_destroy_image(sys_info->graphic.mlx, sys_info->graphic.road_img);
	if (sys_info->graphic.player_img != NULL)
		mlx_destroy_image(sys_info->graphic.mlx, sys_info->graphic.player_img);
	if (sys_info->graphic.exit_img != NULL)
		mlx_destroy_image(sys_info->graphic.mlx, sys_info->graphic.exit_img);
	if (sys_info->graphic.collect_img != NULL)
		mlx_destroy_image(sys_info->graphic.mlx, sys_info->graphic.collect_img);
	if (sys_info->graphic.overlap_img != NULL)
		mlx_destroy_image(sys_info->graphic.mlx, sys_info->graphic.overlap_img);
	if (sys_info->graphic.win != NULL)
		mlx_destroy_window(sys_info->graphic.mlx, sys_info->graphic.win);
	if (sys_info->graphic.mlx != NULL)
		mlx_destroy_display(sys_info->graphic.mlx);
	free(sys_info->graphic.mlx);
}
