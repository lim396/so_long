/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:10:46 by shongou           #+#    #+#             */
/*   Updated: 2022/08/25 13:10:48 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_error_handle(t_data *sys_info)
{
	free_map(sys_info->map);
	if (sys_info->graphic.mlx != NULL)
		destroy_mlx(sys_info);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("\e[1;31m===Error===\e[0m\nmlx error\n", 2);
	exit(1);
}

void	stack_error_handle(t_check_item *data, t_stack *stack, char **map)
{
	t_stack	*sentinel;
	t_stack	*stack_next;

	free_map(map);
	sentinel = stack;
	if (sentinel != NULL)
	{
		while (stack->next != NULL)
		{
			stack_next = stack->next;
			stack->next = stack_next->next;
			free(stack_next);
			stack_next = NULL;
		}
	}
	free(sentinel);
	free(data);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("\e[1;31m===Error==\e[0m\nmalloc error\n", 2);
	exit(1);
}
