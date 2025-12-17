#include "cub3.h"

void	move_forward_backward(t_map *map, t_file *file, double speed)
{
	double	new_x;
	double	new_y;

	new_x = map->x_player + cos(map->dir_angle) * speed;
	new_y = map->y_player + sin(map->dir_angle) * speed;
	if (file->map[(int)map->y_player][(int)new_x] != '1')
		map->x_player = new_x;
	if (file->map[(int)new_y][(int)map->x_player] != '1')
		map->y_player = new_y;
}

int	handle_key(int key, t_map *map)
{
	double	speed;
	double	rot_speed;

	speed = 0.15;
	rot_speed = 0.1;
	if (key == 65307)
		cleanup_and_exit(map);
	if (key == 65361)
		rotate_player(map, -rot_speed);
	if (key == 65363)
		rotate_player(map, rot_speed);
	if (key == 119)
		move_forward_backward(map, map->file, speed);
	if (key == 115)
		move_forward_backward(map, map->file, -speed);
	if (key == 97)
		strafe(map, map->file, speed);
	if (key == 100)
		strafe(map, map->file, -speed);
	clear_image(map);
	raycasting_loop(map, map->file);
	mlx_put_image_to_window(map->game->mlx, map->game->win, map->game->img, 0,
		0);
	return (0);
}

void	strafe(t_map *map, t_file *file, double speed)
{
	double	perp_dir_y;
	double	new_x;
	double	new_y;
	double	perp_dir_x;

	perp_dir_x = -sin(map->dir_angle);
	perp_dir_y = cos(map->dir_angle);
	new_x = map->x_player + perp_dir_x * speed;
	new_y = map->y_player + perp_dir_y * speed;
	if (file->map[(int)new_y][(int)new_x] != '1')
	{
		map->x_player = new_x;
		map->y_player = new_y;
	}
}

void	rotate_player(t_map *map, double angle)
{
	map->dir_angle += angle;
	if (map->dir_angle < 0)
		map->dir_angle += 2 * M_PI;
	if (map->dir_angle >= 2 * M_PI)
		map->dir_angle -= 2 * M_PI;
}

void	put_pixel(t_map *map, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= map->screen_width || y >= map->screen_height)
		return ;
	dst = map->game->addr + (y * map->game->line_length + x
			* (map->game->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
