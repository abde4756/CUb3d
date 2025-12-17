#include "cub3.h"

static double	direction_angle_from_char(char c)
{
	if (c == 'N')
		return (3.0 * M_PI / 2.0);
	if (c == 'S')
		return (M_PI / 2.0);
	if (c == 'E')
		return (0.0);
	if (c == 'W')
		return (M_PI);
	return (0.0);
}

static void	trim_trailing_ws(char *s)
{
	int	len;

	if (!s)
		return ;
	len = (int)ft_strlen(s);
	while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r' || s[len
			- 1] == ' ' || s[len - 1] == '\t'))
	{
		s[len - 1] = '\0';
		len--;
	}
}

void	load_all_textures(t_map *map, t_file *file)
{
	trim_trailing_ws(file->no);
	trim_trailing_ws(file->so);
	trim_trailing_ws(file->we);
	trim_trailing_ws(file->ea);
	load_texture(map, 0, file->no);
	load_texture(map, 1, file->so);
	load_texture(map, 2, file->we);
	load_texture(map, 3, file->ea);
}

void	init_mlx(t_map *map, int screen_w, int screen_h)
{
	map->game = malloc(sizeof(t_game));
	map->game->mlx = mlx_init();
	map->game->win = mlx_new_window(map->game->mlx, screen_w, screen_h,
			"Cub3D");
	map->game->img = mlx_new_image(map->game->mlx, screen_w, screen_h);
	map->game->addr = mlx_get_data_addr(map->game->img,
			&map->game->bits_per_pixel, &map->game->line_length,
			&map->game->endian);
	mlx_hook(map->game->win, 2, 1L << 0, handle_key, map);
	mlx_hook(map->game->win, 17, 0, close_wind, map);
}

int	creat_window(t_file *file, t_map *map)
{
	int	screen_w;
	int	screen_h;

	screen_w = 1280;
	screen_h = 720;
	map->screen_height = screen_h;
	map->screen_width = screen_w;
	map->file = file;
	map->dir_angle = direction_angle_from_char(map->direction);
	map->fov = 60;
	init_mlx(map, screen_w, screen_h);
	load_all_textures(map, file);
	raycasting_loop(map, file);
	mlx_put_image_to_window(map->game->mlx, map->game->win, map->game->img, 0,
		0);
	mlx_loop(map->game->mlx);
	return (0);
}
