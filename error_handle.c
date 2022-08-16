#include "so_long.h"

void	mlx_error_handle(t_data *sys_info)
{
	free_map(sys_info->map);
	if (sys_info->graphic.mlx != NULL)
	{
		destroy_mlx(sys_info);
//		if (sys_info->graphic.win != NULL)
//			mlx_destroy_window(sys_info->graphic.win);
//		if (sys_info->graphic.wall_img != NULL)
//			mlx_destroy_image(sys_info->graphic.wall_img);
//		if (sys_info->graphic.road_img != NULL)
//			mlx_destroy_image(sys_info->graphic.road_img);
//		if (sys_info->graphic.player_img != NULL)
//			mlx_destroy_image(sys_info->graphic.player_img);
//		if (sys_info->graphic.exitimg != NULL)
//			mlx_destroy_image(sys_info->graphic.exit_img);
//		if (sys_info->graphic.collect_img != NULL)
//			mlx_destroy_image(sys_info->graphic.collect_img);
//		if (sys_info->graphic.overlap_img != NULL)
//			mlx_destroy_image(sys_info->graphic.overlap_img);
	}
	free(sys_info->graphic.mlx);
	ft_putstr_fd("\e[1;31m===Error==\e[0m\nmlx error\n", 2);
}

void	stack_error_handle(t_check_item *data, t_stack *stack, char **map)
{
//	int	i;
	t_stack	*sentinel;
	t_stack *stack_next;

//	i = 0;
//	while (map[i])
//		free(map[i++]);
//	free(map);
	free_map(map);
	sentinel = stack;
	while (stack->next != NULL)
	{
		stack_next = stack->next;
		stack->next = stack_next->next;
		free(stack_next);
		stack_next = NULL;
	}
	free(sentinel);
	free(data);
	ft_putstr_fd("\e[1;31m===Error==\e[0m\nmalloc error\n", 2);
}
