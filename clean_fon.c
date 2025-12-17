#include "cub3.h"

static void	destroy_textures_and_images(t_map *map)
{
	int	i;

	i = 0;
	if (!map || !map->game)
		return ;
	while (i < 4)
	{
		if (map->textur[i].imag)
			mlx_destroy_image(map->game->mlx, map->textur[i].imag);
		map->textur[i].imag = NULL;
		i++;
	}
	if (map->game->img)
	{
		mlx_destroy_image(map->game->mlx, map->game->img);
		map->game->img = NULL;
	}
}

static void	free_file_data(t_file *file)
{
	int	i;

	if (!file)
		return ;
	free(file->no);
	free(file->so);
	free(file->we);
	free(file->ea);
	free(file->f);
	free(file->c);
	free(file->gard_first_line_map);
	if (file->map)
	{
		i = 0;
		while (file->map[i])
		{
			free(file->map[i]);
			i++;
		}
		free(file->map);
		file->map = NULL;
	}
}

void	cleanup(t_map *map)
{
	if (!map || !map->game)
		return ;
	destroy_textures_and_images(map);
	if (map->game->win)
	{
		mlx_destroy_window(map->game->mlx, map->game->win);
		map->game->win = NULL;
	}
	if (map->game->mlx)
	{
		mlx_destroy_display(map->game->mlx);
		free(map->game->mlx);
		map->game->mlx = NULL;
	}
	free(map->game);
	map->game = NULL;
	free_file_data(map->file);
}

void	cleanup_and_exit(t_map *map)
{
	cleanup(map);
	exit(0);
}

int	close_wind(t_map *data)
{
	cleanup_and_exit(data);
	return (0);
}
