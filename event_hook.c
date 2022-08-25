/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:10:56 by shongou           #+#    #+#             */
/*   Updated: 2022/08/25 13:10:58 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	quit_game(t_data *sys_info)
{
	free_map(sys_info->map);
	destroy_mlx(sys_info);
	exit(0);
}

static void	proc_press_wasd(int keycode, t_data *sys_info)
{
	if (keycode == KEY_W)
		move_player(sys_info->p_status.y - 1, sys_info->p_status.x, sys_info);
	if (keycode == KEY_A)
		move_player(sys_info->p_status.y, sys_info->p_status.x - 1, sys_info);
	if (keycode == KEY_S)
		move_player(sys_info->p_status.y + 1, sys_info->p_status.x, sys_info);
	if (keycode == KEY_D)
		move_player(sys_info->p_status.y, sys_info->p_status.x + 1, sys_info);
}

static int	proc_press_wasd_esc(int keycode, t_data *sys_info)
{
	if (keycode == KEY_ESC)
		quit_game(sys_info);
	else if (sys_info->finish_flag == 0)
		proc_press_wasd(keycode, sys_info);
	else
		return (0);
	draw_map(sys_info);
	if (sys_info->finish_flag == 1)
	{
		ft_putstr_fd("\n\e[5;36m===Success!===\e[0m\n\n", 1);
		ft_putstr_fd("Quit game: Press esc or click X mark\n", 1);
	}
	return (0);
}

void	event_hook(t_data *sys_info)
{
	mlx_hook(sys_info->graphic.win, KEY_PRESS, 1L << 0, \
			&proc_press_wasd_esc, sys_info);
	mlx_hook(sys_info->graphic.win, EXPOSE, 1L << 15, &draw_map, sys_info);
	mlx_hook(sys_info->graphic.win, DESTROY, 0L, &quit_game, sys_info);
	mlx_hook(sys_info->graphic.win, FOCUSIN, 1L << 21, &draw_map, sys_info);
}
