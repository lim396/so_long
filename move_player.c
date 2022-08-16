#include "so_long.h"

void	swap_pos(char next_pos_elem, int next_y, int next_x, t_data *sys_info)
{
	sys_info->map[next_y][next_x] = next_pos_elem;
	sys_info->map[sys_info->p_status.y][sys_info->p_status.x] = '0';
	if (sys_info->p_status.y == sys_info->exit_y
		&& sys_info->p_status.x == sys_info->exit_x)
		sys_info->map[sys_info->p_status.y][sys_info->p_status.x] = 'E';
	//p_status.x
	//p_status.y here updata?
}

void	update_player_status(char next_pos_elem, t_data *sys_info)
{
	if (next_pos_elem == 'E' || next_pos_elem == '0')
		sys_info->p_status.moves_count += 1;
	if (next_pos_elem == 'C')
	{
		sys_info->p_status.collected += 1;
		sys_info->p_status.moves_count += 1;
	}
	ft_putstr_fd("moves_cont: ", 1);
	ft_putnbr_fd(sys_info->p_status.moves_count, 1);
	ft_putstr_fd("\n", 1);
//	printf("moves_conut: %d\n", sys_info->p_status.moves_count);
}

void	move_player(int y, int x, t_data *sys_info)
{
	if (sys_info->map[y][x] == 'E'
		&& sys_info->all_collectibles == sys_info->p_status.collected)
	{
		swap_pos('E', y, x, sys_info);
		update_player_status('E', sys_info);
		sys_info->finish_flag = 1;
	}
	else if (sys_info->map[y][x] == 'E')	
	{
		swap_pos('P', y, x, sys_info);
		update_player_status('E', sys_info);
	}
	else if (sys_info->map[y][x] == 'C')
	{
		swap_pos('P', y, x, sys_info);
		update_player_status('C', sys_info);
	}
	else if (sys_info->map[y][x] == '0')
	{
		swap_pos('P', y, x, sys_info);
		update_player_status('E', sys_info);
	}
	else
		return ;		
}
