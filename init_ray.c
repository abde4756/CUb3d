#include "cub3.h"

void	init_step_and_side_dist(t_map *map, t_dda *dda)
{
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (map->x_player - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - map->x_player)
			* dda->delta_dist_x;
	}
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (map->y_player - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - map->y_player)
			* dda->delta_dist_y;
	}
}

void	init_dda(t_map *map, t_dda *dda)
{
	dda->map_x = (int)map->x_player;
	dda->map_y = (int)map->y_player;
	if (dda->ray_dir_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
	if (dda->ray_dir_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
	init_step_and_side_dist(map, dda);
}

void	clear_image(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->screen_height)
	{
		x = 0;
		while (x < map->screen_width)
		{
			put_pixel(map, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

int	verify_last_line(t_file *file)
{
	int	j;
	int	i;

	j = 0;
	i = file->count_map_lines - 1;
	while (file->map[i][j] != '\0' && file->map[i][j] != '\n')
	{
		if (file->map[i][j] != '1' && file->map[i][j] != ' ')
			return (-1);
		if (file->map[i][j] == ' ')
		{
			if (file->map[i - 1][j] != '1' && file->map[i - 1][j] != ' '
				&& file->map[i - 1][j])
				return (-1);
		}
		j++;
	}
	return (0);
}
