#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <assert.h>
#include "libft/libft.h"
#include "get_next_line.h"
//#include "mlx.h"
#include "./minilibx-linux/mlx.h"

# define KEY_PRESS 2
# define EXPOSE 12
# define FOCUSIN 9
# define DESTROY 17 //33?

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define IMG_SIZE 32
# define ROAD_IMG "img/road.xpm"
# define WALL_IMG "img/wall.xpm"
# define PLAYER_IMG "img/player.xpm"
# define EXIT_IMG "img/exit.xpm"
# define COLLECT_IMG "img/collect.xpm" //"img/orb.xpm"
# define OVERLAP_IMG "img/overlap_exit.xpm"

typedef struct s_graphic	t_graphic;
struct s_graphic
{
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*road_img;
	void	*player_img;
	void	*exit_img;
	void	*collect_img;
	void	*overlap_img;
};

typedef struct s_status	t_status;
struct s_status
{
	int	x; //pos
	int	y; //pos
	int	moves_count;
	int	collected;
};

typedef struct s_data	t_data;
struct s_data
{
	t_graphic	graphic; //within map?
	t_status	p_status;
	char		**map;
	int			all_collectibles;
	bool		finish_flag;
	int			exit_x;
	int			exit_y;
};

typedef struct s_stack	t_stack;
struct s_stack
{
	t_stack	*next;
	int		branch_x;
	int		branch_y;
};

typedef struct s_check_item t_check_item;
struct s_check_item
{
	int		x;
	int		y;
	bool	exit_flag;
	int		collectible;
};

//read_map
char	**read_map(char *map_file);

//check_extension
bool	check_extension(char *file_name);


//check_map_rule
bool	is_surrounded_wall(char **map);
bool	is_rerectangle(char **map);
bool	is_valid_map_elements(char **map);
bool	is_complete_game(char **map);
bool	check_map(char **map);

//check_map_utiles
bool	is_move(char **map, t_check_item *data);
void	get_start_status(char **map, t_check_item *data, int *all_collect);
int		measure_map_height(char **map);
bool	is_count_elem(char map_elem, int *p_count, int *e_count, int *c_count);

//stack
t_stack	*new_node(t_check_item *data);
t_stack	*new_sentinel(void);
int		push(t_stack *stack, t_check_item *data); //change int ?
void	pop(t_stack *stack);

//tansaku zi syori
int		countdirections_can_go(char **map, t_check_item *data);
int		save_branch_point(t_check_item *data, t_stack *branch_p, char **map); //rename
void	check_item(char map, t_check_item *data);
void	warp_branch_point(t_check_item *data, t_stack *branch_pos);

//map tansaku
void	move_up(char **map, t_check_item *data, t_stack *branch_pos);
void	move_down(char **map, t_check_item *data, t_stack *branch_pos);
void	move_left(char **map, t_check_item *data, t_stack *branch_pos);
void	move_right(char **map, t_check_item *data, t_stack *branch_pos);


//event
void	event_hook(t_data *sys_info);
int		proc_press_wasd_esc(int keycode, t_data *sys_info);
int		quit_game(t_data *sys_info);

//init_data
void	init_graphic(t_data *sys_info, int win_width, int win_height);
void	init_player_status(t_data *sys_info);
int		get_total_collect(char **map);
void	get_exit_pos(t_data *sys_info);
void	init_sys_data(t_data *sys_info);

//draw_map
void	draw_to_window(void *img, t_data *sys_info, int y, int x);
void	draw_and_now_pos(t_data *sys_info, int y, int x);
int		draw_map(t_data *sys_info);

//move_player
void	swap_pos(char next_pos_elem, int next_y, int next_x, t_data *sys_info);
void	update_player_status(char next_pos_elem, t_data *sys_info);
void	move_player(int y, int x, t_data *sys_info);


void	free_map(char **map);
void	destroy_mlx(t_data *sys_info);

void	mlx_error_handle(t_data *sys_info);
void	stack_error_handle(t_check_item *data, t_stack *stack, char **map);

#endif
