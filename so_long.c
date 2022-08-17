#include "so_long.h"

bool	check_extension(char *file_name)
{
	char	*extensions_pos;

	if (file_name == NULL)
		return (false);
	extensions_pos = ft_strrchr(file_name, '.');
	if (extensions_pos == NULL)
		return (false);
	if (ft_strncmp(extensions_pos, ".ber", 5) != 0)
		return (false);
	return (true);
}

char	**read_map(char *map_file)
{
	int		fd;
	char	*add_line;
	char	*added_line;
	char	*map_1d;
	char	**map_2d;

	map_1d = ft_strdup("");
	if (map_1d == NULL)
		return (NULL);
	fd = open(map_file, O_RDONLY);
	while (1)
	{
		add_line = get_next_line(fd);
		if (add_line == NULL)
			break ;
		added_line = map_1d;
		map_1d = ft_strjoin(added_line, add_line);
		free(added_line);
		free(add_line);
	}
	close(fd);
	map_2d = ft_split(map_1d, '\n');
	free(map_1d);
	return (map_2d);
}

void	print_extension_error(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("\e[1;31m===Error===\e[0m\n", 2);
	ft_putstr_fd("This file is invalid extension,", 2);
	ft_putstr_fd("\nPlease read the file with extension .ber\n", 2);
}

void	print_map_error(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("\e[1;31m===Error===\e[0m\n", 2);
	ft_putstr_fd("This is invalid map, please read valid map\n", 2);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_data	sys_info;

	if (argc != 2)
		exit(1);
	if (!check_extension(argv[1]))
	{
		print_extension_error();
		exit(1);
	}
	map = read_map(argv[1]);
	if (!check_map(map))
	{
		free_map(map);
		print_map_error();
		exit(1);
	}
	free_map(map);
	sys_info.map = read_map(argv[1]);
	init_sys_info(&sys_info);
	draw_map(&sys_info);
	print_moves_count(&sys_info);
	event_hook(&sys_info);
	mlx_loop(sys_info.graphic.mlx);
	return (0);
}
